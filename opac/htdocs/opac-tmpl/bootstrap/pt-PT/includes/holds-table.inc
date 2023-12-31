[% USE Branches %]
[% USE ItemTypes %]
[% USE KohaDates %]
[% PROCESS 'i18n.inc' %]

[% IF ( HOLDS.count ) %]
 <div id="opac-user-holds" class="tab-pane" role="tabpanel" aria-labelledby="opac-user-holds-tab">
 <table id="holdst" class="table table-bordered table-striped">
 <caption>Reservas <span class="count">([% HOLDS.count | html %] total)</span></caption>
 <!-- HOLDS TABLE ROWS -->
 <thead>
 <tr>
 <th class="anti-the">Título</th>
 [% IF ( showpriority ) %]
 <th>Colocado em</th>
 [% ELSE %]
 <th class="psort">Colocado em</th>
 [% END %]
 <th>Expira em</th>
 [% UNLESS( singleBranchMode) %]
 <th>Biblioteca de levantamento</th>
 [% END %]
 [% IF ( showpriority ) %]
 <th class="psort">Prioridade</th>
 [% END %]
 <th>Estado</th>
 [% IF SuspendHoldsOpac and ! onlyinfo %]
 <th class="nosort" >Suspender</th>
 [% END %]
 [% IF ! onlyinfo %]
 <th class="nosort">Modificar</th>
 [% END %]
 <th></th>
 </tr>
 </thead>
 <tbody>
 [% SET all_holds_waiting = 1 %]
 [% FOREACH HOLD IN HOLDS %]
 [% UNLESS ( HOLD.is_waiting || HOLD.is_in_transit || HOLD.is_in_processing) %]
 [% SET all_holds_waiting = 0 %]
 [% END %]
 [% IF ( HOLD.is_at_destination ) %]
 <tr class="reserved">
 [% ELSIF HOLD.is_in_transit %]
 <tr class="transfered">
 [% ELSE %]
 <tr>
 [% END %]
 <td class="title">
 [% IF ! onlyinfo %]
 [% INCLUDE 'biblio-title.inc' biblio=HOLD.biblio link=> 1 %]
 [% HOLD.item.enumchron | html %]
 [% ELSE %]
 <strong>
 [% INCLUDE 'biblio-title.inc' biblio=HOLD.biblio %]
 [% HOLD.item.enumchron | html %]
 </strong>
 [% END %]
 [% HOLD.biblio.author | html %]
 [% IF HOLD.item_group_id %]
 <p>Próximo exemplar disponível do grupo: <strong>[% HOLD.item_group.description | html %]</strong></p>
 [% END %]
 [% IF HOLD.item_level_hold %]
 <p class="hint">Exemplar reservado: [% HOLD.item.barcode | html %]</p>
 [% END %]
 </td>
 <td class="reservedate" data-order="[% HOLD.reservedate | html %]">
 <span class="tdlabel">Data de reserva:</span>
 [% HOLD.reservedate | $KohaDates %]
 </span>
 </td>
 [% IF ! HOLD.found %]
 <td class="expirationdate" data-order="[% HOLD.expirationdate | html %]">
 [% IF ( HOLD.expirationdate ) %]
 <span class="tdlabel">Fim:</span>
 [% HOLD.expirationdate | $KohaDates %]
 [% ELSE %]
 <span class="tdlabel">Fim:</span>
 Nunca expira [% END %] [% ELSE %] <td class="expirationdate" data-order="0000-00-00">
 -
 [% END %]
 </td>
 [% UNLESS( singleBranchMode) %]
 <td class="branch">
 <span class="tdlabel">Biblioteca de levantamento:</span>
 [% HOLD.branch.branchname | html %]
 [% IF ( HOLD.can_update_pickup_location_opac ) %]
 <button type="button" class="btn btn-sm btn-link" data-toggle="modal" data-target="#changePickup[% HOLD.reserve_id | html %]">
 <i class="fa fa-pencil" aria-hidden="true"></i> Modificar </button>
 <!-- Change pickup location modal -->
 <div class="modal" id="changePickup[% HOLD.reserve_id | html %]" tabindex="-1" aria-labelledby="changePickup[% HOLD.reserve_id | html %]Label" aria-hidden="true">
 <div class="modal-dialog">
 <form id="change_branch_form[% HOLD.reserve_id | html %]" action="/cgi-bin/koha/opac-modrequest.pl" method="post">
 <div class="modal-content">
 <div class="modal-header">
 <h5 class="modal-title" id="changePickup[% HOLD.reserve_id | html %]Label">Modificar a biblioteca de levantamento de <em>[% INCLUDE 'biblio-title.inc' biblio=HOLD.biblio %]</em></h5>
 <button aria-label="Fechar" class="closebtn" data-dismiss="modal" type="button">
 <span aria-hidden="true">&times;</span>
 </button>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="new_branch[% HOLD.reserve_id | html %]">Nova biblioteca de levantamento:</label>
 <select name="new_pickup_location" id="new_branch[% HOLD.reserve_id | html %]" class="form-control">
 [% PROCESS options_for_libraries libraries = Branches.pickup_locations({ search_params => { biblio => HOLD.biblionumber, patron => HOLD.borrower }, selected => HOLD.branchcode }) %]
 </select>
 </div>
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 </div>
 <div class="modal-footer">
 <button type="submit" name="change_branch" value="1" class="btn btn-primary"><i class="fa fa-check" aria-hidden="true"></i> Guardar</button>
 <button type="button" class="btn btn-secondary" data-dismiss="modal"><i class="fa fa-remove" aria-hidden="true"></i> Anular</button>
 </div>
 </div> <!-- /.modal-content -->
 </form>
 </div> <!-- /.modal-dialog -->
 </div> <!-- /.modal -->
 [% END  %]
 </td>
 [% END %]
 [% IF ( showpriority ) %]
 <td data-order="[% HOLD.priority | html %]" class="priority">
 <span class="tdlabel">Prioridade:</span>
 [% HOLD.priority | html %]
 </td>
 [% END %]
 <td class="status">
 <span class="tdlabel">Estado:</span>
 [% IF ( HOLD.is_waiting ) %]
 <i class="fa fa-exclamation-circle text-warning" aria-hidden="true"></i>
 [% IF ( HOLD.is_at_destination ) %] Exemplar à espera em <strong> [% HOLD.branch.branchname | html %]</strong>
 [% IF ( HOLD.desk_id ) %], [% HOLD.desk.desk_name | html %],[% END %] [% IF ( HOLD.waitingdate ) %] desde [% HOLD.waitingdate | $KohaDates %] [% IF HOLD.expirationdate %] até [% HOLD.expirationdate | $KohaDates %] [% END %] [% END %] <input type="hidden" name="pickup" value="[% HOLD.branchcode | html %]" />
 [% ELSE %] Exemplar em trânsito para <strong> [% Branches.GetName( HOLD.branchcode ) | html %]</strong> <input type="hidden" name="pickup" value="[% HOLD.branchcode | html %]" />
 [% END %]
 [% ELSE %]
 [% IF ( HOLD.is_in_transit ) %]
 [% SET transfer = HOLD.item.get_transfer %]
 [% branch_name = BLOCK %]<strong>[% Branches.GetName( transfer.frombranch ) | html %]</strong>[% END %]
 <span>Em trânsito de [% branch_name| $raw %] desde</span>
 [% transfer.datesent | $KohaDates %]
 [% ELSIF ( HOLD.is_in_processing ) %]
 <span>Exemplar em processamento</span>
 [% ELSIF ( HOLD.suspend ) %]
 <span>Suspensa</span>[% IF ( HOLD.suspend_until ) %] <span>até</span> [% HOLD.suspend_until | $KohaDates %][% END %]
 [% ELSE %]
 [% IF HOLD.itemtype %]
 <span>Pendente para o próximo exemplar do tipo de documento '[% ItemTypes.GetDescription( HOLD.itemtype ) | html %]'</span>
 [% ELSE %]
 <span>Pendente</span>
 [% END %]
 [% END %]
 [% END %]
 </td>
 [% IF SuspendHoldsOpac and ! onlyinfo %]
 <td>
 [% IF ( HOLD.is_cancelable_from_opac ) %]
 [% IF HOLD.suspend %]
 <form class="form-inline" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button class="btn btn-link" type="submit" name="submit"><i class="fa fa-play" aria-hidden="true"></i> Retomar</button>
 </form>
 [% ELSE %]
 [% IF AutoResumeSuspendedHolds %]
 <a class="btn btn-link suspend_hold js-show" href="#" role="button" data-title="[% HOLD.biblio.title | html %] [% FOREACH subtitle IN HOLD.biblio.subtitle.split(' \| ') %][% IF Koha.Preference('marcflavour')=='UNIMARC' %],[% END %][% subtitle | html %][% END %]" data-reserve_id="[% HOLD.reserve_id | html %]"><i class="fa fa-pause" aria-hidden="true"></i> Suspender</a>
 [% ELSE %]
 <form class="form-inline" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button class="btn btn-link" type="submit" name="submit"><i class="fa fa-pause" aria-hidden="true"></i> Suspender</button>
 </form>
 [% END # / IF AutoResumeSuspendedHolds %]
 [% END # / IF HOLD.suspend %]
 [% END # / IF ( HOLD.is_cancelable_from_opac )%]
 </td>
 [% END # / IF SuspendHoldsOpac %]
 [% IF ! onlyinfo %]
 <td class="modify">
 [% IF ( HOLD.is_cancelable_from_opac ) %]
 <form id="delete_hold_[% HOLD.reserve_id | html %]" action="/cgi-bin/koha/opac-modrequest.pl" method="post">
 <input type="hidden" name="biblionumber" value="[% HOLD.biblionumber | html %]" />
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button data-title="[% INCLUDE 'biblio-title-head.inc' biblio=HOLD.biblio %]" data-reserve_id="[% HOLD.reserve_id | html %]" type="submit" class="btn btn-sm btn-danger btn-delete-hold"><i class="fa fa-remove" aria-hidden="true"></i> [% tp('Cancel hold button', 'Cancel') | html %]</button>
 </form>
 [% ELSIF HOLD.is_waiting && HOLD.cancellation_requestable_from_opac %]
 <form id="req_cancel_hold_[% HOLD.reserve_id | html %]" action="/cgi-bin/koha/opac-modrequest.pl" method="post">
 <input type="hidden" name="biblionumber" value="[% HOLD.biblionumber | html %]" />
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <input type="hidden" name="cancellation_request" value="1" />
 <button data-title="[% INCLUDE 'biblio-title-head.inc' biblio=HOLD.biblio %]" data-reserve_id="[% HOLD.reserve_id | html %]" type="submit" class="btn btn-sm btn-danger btn-req-delete-hold"><i class="fa fa-remove" aria-hidden="true"></i> [% tp('Cancel hold button', 'Cancel') | html %]</button>
 </form>
 [% END %]
 </td>
 <td></td>
 [% END # / IF onlyinfo %]
 </tr>
 [% END # /FOREACH HOLDS %]
 </tbody>
 </table>

 [% IF SuspendHoldsOpac and ! onlyinfo %]
 [% UNLESS ( all_holds_waiting ) %]
 <div>
 <form class="form-inline" id="suspend_all_holds" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 <button type="submit" id="suspend_all_submit" class="btn btn-primary"><i class="fa fa-pause" aria-hidden="true"></i> Suspender todas as reservas</button>
 <input type="hidden" name="suspend" value="1" />

 [% IF AutoResumeSuspendedHolds %]
 <label for="suspend_until"> até </label>
 <input type="text" name="suspend_until" id="suspend_until" class="flatpickr futuredate" size="10" />
 <p><a href="#" class="clear-flatpickr" data-fp="suspend_until">Limpar data para suspender por tempo indeterminado</a></p>
 [% END %]
 </form>
 </div>
 <br/>
 <div>
 <form id="resume_all_holds" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 <button type="submit" id="resume_all_submit" class="btn btn-primary"><i class="fa fa-play" aria-hidden="true"></i> Retomar todas as reservas suspensas</button>
 <input type="hidden" name="suspend" value="0" />
 </form>
 </div>
 [% END %]
 [% END %]
 </div> <!-- / #opac-user-holds -->
[% END # / #HOLDS.count %]
