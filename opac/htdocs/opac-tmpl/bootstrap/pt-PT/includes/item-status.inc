[% USE Branches %]
[% USE Koha %]
[% USE AuthorisedValues %]
[% SET itemavailable = 1 %]

[%#- This include takes two parameters: an item structure -%]
[%#- and an optional loan (issue) structure.  The issue -%]
[%#- structure is used by course reserves pages, which do -%]
[%#- not use an API to fetch items that populates item.datedue. -%]

[% UNLESS item.isa('Koha::Item') %]
 <div>Erro de programação, o ficheiro item-status.inc deve ser invocado com um objeto Koha::Item.<div>
 [% STOP %]
[% END %]

[% SET transfer = item.get_transfer %]
[% IF transfer AND transfer.in_transit %]
 [% SET transfertwhen = transfer.datesent %]
 [% SET transfertfrom = transfer.frombranch %]
 [% SET transfertto = transfer.tobranch %]
[% END %]

[% SET checkout = item.checkout %]
[% SET waiting  = item.holds.waiting.count %]
[% IF include_schema_org %]
 [% IF item.damaged or checkout or item.itemlost or transfertwhen or waiting %]
 <link property="availability" href="http://schema.org/OutOfStock" />
 [% ELSIF item.withdrawn %]
 <link property="availability" href="http://schema.org/Discontinued" />
 [% ELSIF item.notforloan or item.itemtype.notforloan %]
 <link property="availability" href="http://schema.org/InStoreOnly" />
 [% ELSE %]
 <link property="availability" href="http://schema.org/InStock" />
 [% END %]
[% END %]

[% IF ( item.itemlost ) %]
 [% SET itemavailable = 0 %]
 [% itemlost_lib = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.itemlost', authorised_value => item.itemlost, opac => 1 ) %]
 [% IF itemlost_lib %]
 <span class="item-status lost">[% itemlost_lib | html %]</span>
 [% ELSE %]
 <span class="item-status lost">Exemplar perdido</span>
 [% END %]
[% END %]

[% IF checkout %]
 [% SET checkout_patron = checkout.patron %]
 [% SET onsite_checkout = checkout.onsite_checkout %]

 [% SET itemavailable = 0 %]
 [% IF onsite_checkout %]
 [% IF ( Koha.Preference('OPACShowCheckoutName') ) %]
 <span class="item-status checkedout">Atualmente em uso local por [% checkout_patron.firstname | html %] [% checkout_patron.surname | html %] [% IF ( checkout_patron.cardnumber ) %]([% checkout_patron.cardnumber | html %])[% END %]</span>
 [% ELSE %]
 <span class="item-status checkedout">Atualmente em uso local</span>
 [% END %]
 [% ELSE %]
 [% IF ( Koha.Preference('OPACShowCheckoutName') ) %]
 <span class="item-status checkedout">Emprestado a [% checkout_patron.firstname | html %] [% checkout_patron.surname | html %] [% IF ( checkout_patron.cardnumber ) %]([% checkout_patron.cardnumber | html %])[% END %]</span>
 [% ELSE %]
 <span class="item-status checkedout">Emprestado</span>
 [% END %]
 [% END %]
 [% IF show_recall_link %]
 [% IF logged_in_user.borrowernumber != issue.borrowernumber %]
 <a href="/cgi-bin/koha/opac-recall.pl?biblionumber=[% item.biblionumber | uri %]" class="btn btn-default btn-xs">Reclamar</a>
 [% END %]
 [% END %]
[% END %]

[% IF transfertwhen %] [%# transfertwhen is set in C4::Search, do not have it for course reserves %]
 [% SET itemavailable = 0 %]
 <span class="item-status intransit">Em trânsito de [% Branches.GetName( transfertfrom ) | html %] para [% Branches.GetName( transfertto ) | html %] desde [% transfertwhen | $KohaDates %]</span>
[% END %]

[% IF waiting OR item.holds.processing.count %]
 [% SET itemavailable = 0 %]
 <span class="item-status onhold">Reservado</span>
[% END %]

[% IF ( item.withdrawn ) %]
 [% SET itemavailable = 0 %]
 [% withdrawn_lib = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.withdrawn', authorised_value => item.withdrawn, opac => 1 ) %]
 [% IF withdrawn_lib %]
 <span class="item-status withdrawn">[% withdrawn_lib | html %]</span>
 [% ELSE %]
 <span class="item-status withdrawn">Exemplar retirado</span>
 [% END %]
[% END %]


[% SET restricted_lib = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.restricted', authorised_value => item.restricted, opac => 1 ) %]
[% IF item.notforloan %]
 [% SET itemavailable = 0 %]
 [% notforloan_lib = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.notforloan', authorised_value => item.notforloan, opac => 1 ) %]
 [% IF notforloan_lib %]
 <span class="item-status notforloan">[% notforloan_lib | html %] [% IF restricted_lib %]<span class="restricted">([% restricted_lib | html %])</span>[% END %]</span>
 [% ELSE %]
 <span class="item-status notforloan">Não emprestável [% IF restricted_lib %]<span class="restricted">([% restricted_lib | html %])</span>[% END %]</span>
 [% END %]
[% ELSIF item.itemtype.notforloan %]
 [% SET itemavailable = 0 %]
 <span class="item-status notforloan">Não emprestável [% IF restricted_lib %]<span class="restricted">([% restricted_lib | html %])</span>[% END %]</span>
[% END %]

[% IF ( item.bundle_host ) %]
 <span class="bundled">No conjunto: <a href="/cgi-bin/koha/opac-detail.pl?biblionumber=[% item.bundle_host.biblionumber | uri %]">[% INCLUDE 'biblio-title.inc' biblio = item.bundle_host.biblio %]</a></span>
[% END %]

[% IF ( item.damaged ) %]
 [% SET itemavailable = 0 %]
 [% av_lib_include = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.damaged', authorised_value => item.damaged, opac => 1 ) %]
 [% IF av_lib_include %]
 <span class="item-status damaged">[% av_lib_include | html %]</span>
 [% ELSE %]
 <span class="item-status damaged">Exemplar danificado</span>
 [% END %]
[% END %]

[% IF Koha.Preference('OPACAcquisitionDetails') AND item.orders.filter_by_active.count %]
 [% SET itemavailable = 0 %]
 <span class="item-status onorder">Encomendado</span>
[% END %]

[% IF item.has_pending_hold %]
 [% SET itemavailable = 0 %]
 <span class="item-status pendinghold">Reserva pendente</span>
[% END %]

[% IF Koha.Preference('UseRecalls') && item.has_pending_recall %]
 [% SET itemavailable = 0 %]
 <span class="item-status pendingrecall">Reclamação pendente</span>
[% END %]

[% IF ( itemavailable ) %]
 <span class="item-status available">Disponível [% IF restricted_lib %]<span class="restricted">([% restricted_lib | html %])</span>[% END %]</span>
[% END %]
