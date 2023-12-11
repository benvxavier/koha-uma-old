<p id="return-claims-controls">
 [% IF ( patron.return_claims.resolved.count > 0 || patron.return_claims.unresolved.count > 0 ) %]
 <a id="show_all_claims" class="ctrl_link" href="#">Mostrar todas [% patron.return_claims.count | html %] reclamações</a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#">Mostrar [% patron.return_claims.unresolved.count | html %] reclamações não resolvidas</a>
 [% ELSE %]
 <a id="show_all_claims" class="ctrl_link" href="#"></a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#"></a>
 [% END %]
</p>
<table id="return-claims-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="return-claim-id">ID da reclamação</th>
 <th class="return-claim-id">Resolvido?</th>
 <th class="return-claim-record-title anti-the">Título</th>
 <th class="return-claim-notes">Notas</th>
 <th class="return-claim-created-on">Criado em</th>
 <th class="return-claim-created-on">Criado em</th>
 <th class="return-claim-updated-on">Atualizado em</th>
 <th class="return-claim-updated-on">Atualizado em</th>
 <th class="return-claim-resolution">Resolução</th>
 <th class="return-claim-actions NoSort">&nbsp;</th>
 </tr>
 </thead>
</table>
