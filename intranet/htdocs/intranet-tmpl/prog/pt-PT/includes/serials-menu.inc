<div id="navmenu">
 <div id="navmenulist">
 <h5>Periódicos</h5>
 <ul>
 [% IF ( subscriptionid ) %]
 <li><a href="/cgi-bin/koha/serials/serials-collection.pl?subscriptionid=[% subscriptionid | uri %]">Coleção de periódico</a></li>
 [% UNLESS closed %]
 [% IF ( routing && CAN_user_serials_routing ) %]
 [% IF ( hasRouting ) %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]">Modificar a lista de circulação</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]&amp;op=new">Criar uma lista de circulação</a></li>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF ( CAN_user_serials_claim_serials ) %]
 <li><a href="/cgi-bin/koha/serials/claims.pl">Reclamações</a></li>
 [% END %]
 [% IF ( CAN_user_serials_check_expiration ) %]
 <li><a href="/cgi-bin/koha/serials/checkexpiration.pl">Verificação das datas que expira</a></li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-frequencies.pl">
 Gerir periodicidades </a>
 </li>
 <li>
 <a href="/cgi-bin/koha/serials/subscription-numberpatterns.pl">
 Gerir modelos de numeração </a>
 </li>
 [% IF Koha.Preference('Mana') == 1 %]
 <li><a href="/cgi-bin/koha/serials/serials-search.pl?mana=1">Pesquisar no Mana</a></li>
 [% END %]
 [% IF CAN_user_serials_edit_subscription && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=subscription">Gerir os campos das assinaturas</a>
 </li>
 [% END %]
 </ul>

 [% IF ( CAN_user_reports ) %]
 <h5>Relatórios</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Assistente de estatísticas de periódicos</a></li>
 </ul>
 [% END %]

 </div>
</div>
