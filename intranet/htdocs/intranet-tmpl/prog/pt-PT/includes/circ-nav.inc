[% USE Koha %]
[% USE Branches %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>Empréstimo</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/circulation.pl">Emprestar</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/returns.pl">Devolver</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/renew.pl">Renovar</a>
 </li>
 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary ) %]
 <li>
 [% IF Koha.Preference('UseCirculationDesks') %]
 <a href="/cgi-bin/koha/circ/set-library.pl">Definir biblioteca e balcão</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/circ/set-library.pl">Escolher a biblioteca</a>
 [% END %]
 </li>
 [% ELSIF Koha.Preference('UseCirculationDesks') %]
 <li>
 <a href="/cgi-bin/koha/circ/set-library.pl">Definir balcão</a>
 </li>
 [% END %]
 [% IF ( fast_cataloging && CAN_user_editcatalogue_fast_cataloging ) %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/addbiblio.pl?frameworkcode=FA"> Catalogação rápida</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('AllowCheckoutNotes') && CAN_user_circulate_manage_checkout_notes ) %]
 <li>
 <a href="/cgi-bin/koha/circ/checkout-notes.pl">Notas de empréstimo</a>
 </li>
 [% END %]
 [% IF Koha.Preference('OnSiteCheckouts') %]
 <li>
 <a href="/cgi-bin/koha/circ/on-site_checkouts.pl">Empréstimos on-site</a>
 </li>
 [% END %]
 </ul>

 <h5>Reservas</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/view_holdsqueue.pl">Fila de espera</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/pendingreserves.pl">Reservas a processar</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/waitingreserves.pl">Reservas por levantar</a>
 </li>
 [% IF ( Koha.Preference('CurbsidePickup') && CAN_user_circulate_manage_curbside_pickups ) %]
 <li>
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl">Levantamentos de rua</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/reserveratios.pl">Rácios da reserva</a>
 </li>
 </ul>

 [% IF Koha.Preference('UseRecalls') and CAN_user_recalls %]
 <h5>Reclamações</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_queue.pl" title="Todos as reclamações ativas">Fila de reclamações</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_to_pull.pl" title="Reclamações que podem ser preenchidas mas não foi definidas como em espera">Reclamações a processar</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_overdue.pl" title="Exemplares reclamados que estão em atraso para devolução">Reclamações de atrasos</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_waiting.pl" title="Exemplares reclamados por levantar">Reclamações por levantar</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_old_queue.pl" title="Reclamações inativas">Reclamações antigas</a>
 </li>
 </ul>
 [% END %]

 [% IF Koha.Preference('ArticleRequests') %]
 <h5>Pedido do leitor</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/article-requests.pl">Pedidos de artigo</a>
 </li>
 </ul>
 [% END %]

 <h5>Transferências</h5>
 <ul>
 [% IF !Koha.Preference('IndependentBranchesTransfers') || CAN_user_superlibrarian %]
 <li>
 <a href="/cgi-bin/koha/circ/branchtransfers.pl">Transferência</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/transfers_to_send.pl">Transferências a enviar</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/transferstoreceive.pl">Transferências a receber</a>
 </li>
 </ul>

 <h5>Atrasos</h5>
 <ul>
 [% IF ( CAN_user_circulate_overdues_report ) %]
 <li>
 <a href="/cgi-bin/koha/circ/overdue.pl" title="Aviso: Este relatório exige grande capacidade de processamento quando há muitos exemplares em atraso.">Atrasos</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/branchoverdues.pl" title="Limitado à sua biblioteca. Consulte a ajuda do relatório para outros detalhes.">Atrasos com multas</a>
 </li>
 </ul>
 </div>
</div>
