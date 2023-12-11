[% USE Branches %]
<div id="recalls">
[% IF recalls.count %]
 <table id="recalls-table">
 <thead>
 <tr>
 [% IF checkboxes %]<th class="recall-checkbox nosort">&nbsp;</th>[% END %]
 <th class="recall-title anti-the">Título</th>
 [% UNLESS specific_patron %]<th class="recall-patron">Pedido por</th>[% END %]
 <th class="recall-date">Colocado em</th>
 <th class="recall-expiry">Expira em</th>
 <th class="recall-branch">Biblioteca de levantamento</th>
 <th class="recall-status">Estado</th>
 [% UNLESS viewing_old %]<th class="recall-duedate">Data de devolução</th>[% END %]
 [% UNLESS viewing_old %]<th class="recall-actions nosort">&nbsp;</th>[% END %]
 </tr>
 </thead>

 <tbody>
 [% FOREACH recall IN recalls %]
 [% IF recall.completed %]<tr class="old">[% ELSE %]<tr>[% END %]

 [% IF checkboxes %]
 <td class="recall-checkbox">
 [% IF recall.completed %]
 &nbsp;
 [% ELSE %]
 <input type="checkbox" value="[% recall.id | html %]" name="recall_ids">
 [% END %]
 </td>
 [% END %]

 <td class="recall-title">
 [% INCLUDE 'biblio-title.inc' biblio=recall.biblio link=1 %] [% IF recall.biblio.author %] por [% recall.biblio.author | html %][% END %] [% recall.item.enumchron | html %] [% IF ( recall.item ) %]<br><em>Código de barras: [% recall.item.barcode | html %]</em>[% END %]
 </td>

 [% UNLESS specific_patron %]
 <td class="recall-patron">
 [% INCLUDE 'patron-title.inc' patron=recall.patron hide_patron_infos_if_needed=1 link_to="circulation_recalls" %]
 </td>
 [% END %]

 <td class="recall-date">
 [% recall.created_date | $KohaDates %]
 </td>

 <td class="recall-expiry">
 [% IF ( recall.expiration_date ) %]
 [% recall.expiration_date | $KohaDates %]
 [% ELSIF ( !recall.completed ) %]
 <span>Nunca expira</span>
 [% ELSE %]
 -
 [% END %]
 </td>

 <td class="recall-branch">
 [% recall.library.branchname | html %]
 </td>

 <td class="recall-status">
 [% IF ( recall.in_transit ) %]
 <span>Em trânsito para [% recall.library.branchname | html %]</span>
 [% ELSIF ( recall.waiting ) %]
 <span>Pronta para levantamento</span>
 [% ELSIF ( recall.expired ) %]
 <span>Expirou em [% recall.expiration_date | $KohaDates %]</span>
 [% ELSIF ( recall.cancelled ) %]
 <span>Cancelada em [% recall.completed_date | $KohaDates %] </span>
 [% ELSIF ( recall.overdue ) %]
 <span>Devolução atrasada</span>
 [% ELSIF ( recall.fulfilled ) %]
 <span>Completo</span>
 [% ELSE %]
 <span>Obrigatório</span>
 [% END %]
 </td>

 [% UNLESS viewing_old %]
 <td class="recall-duedate">
 [% IF recall.requested and recall.checkout %]
 <span>Em espera de ser devolvido até [% recall.checkout.date_due | $KohaDates %]</span>
 [% ELSIF recall.waiting and RECALL.expiration_date %]
 <span>Levantamento até [% RECALL.expiration_date | $KohaDates %]</span>
 [% ELSE %]
 -
 [% END %]
 </td>
 [% END %]

 [% UNLESS viewing_old %]
 <td class="recall-cancel actions">
 [% IF recall.completed %]
 &nbsp;
 [% ELSE %]
 <div class="btn-group">
 <button type="button" class="btn btn-sm btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
 Ações <span class="caret"></span>
 </button>
 <ul class="dropdown-menu pull-right">
 [% IF ( recall.requested or recall.overdue ) %]
 <li><a class="cancel_recall" data-id="[% recall.id | html %]" data-action="cancel"><i class="fa fa-times"></i> Anular</a></li>
 [% IF ( recall.should_be_overdue ) %]
 <li><a class="overdue_recall" data-id="[% recall.id | html %]" data-action="overdue"><i class="fa fa-hourglass-end"></i> Marcar como atrasada</a></li>
 [% END %]
 [% ELSIF ( recall.waiting ) %]
 <li><a class="revert_recall" data-id="[% recall.id | html %]" data-action="revert"><i class="fa fa-undo"></i> Reverter espera</a></li>
 <li><a class="expire_recall" data-id="[% recall.id | html %]" data-action="expire"><i class="fa fa-times"></i> Expirado</a></li>
 [% ELSIF ( recall.in_transit ) %]
 <li><a class="transit_recall" data-id="[% recall.id | html %]" data-action="transit"><i class="fa fa-times"></i> Cancelar reclamação e devolver a: [% Branches.GetName(recall.item.homebranch) | html %]</a></li>
 [% END %]
 </ul>
 </div>
 [% END %]
 </td>
 [% END %]

 </tr>
 [% END %]
 </tbody>
 </table>
 [% ELSE %]
 [% IF patron.borrowernumber %]
 <div class="dialog message">O leitor não tem reclamações.</div>
 [% ELSE %]
 <div class="dialog message">Não existem reclamações a mostrar.</div>
 [% END %]
 [% END %]
</div>
