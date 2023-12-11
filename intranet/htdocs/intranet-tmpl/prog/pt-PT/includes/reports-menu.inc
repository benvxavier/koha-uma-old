[% USE Koha %]

<div id="navmenu">
 <div id="navmenulist">

 <h5>Relatórios guiados</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl">Relatórios guiados</a></li>
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Build%20new">Construir novo</a></li>
 [% END %]
 [% IF ( CAN_user_reports_execute_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Use%20saved">Relatórios guardados</a></li>
 [% END %]
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Create%20report%20from%20SQL">Criar a partir de SQL</a></li>
 [% END %]
 </ul>

 <h5>Assistente de estatísticas</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Aquisições</a></li>
 <li><a href="/cgi-bin/koha/reports/borrowers_stats.pl">Leitores</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_stats.pl">Catálogo</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_stats.pl">Empréstimo</a></li>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Periódicos</a></li>
 <li><a href="/cgi-bin/koha/reports/cash_register_stats.pl">Registo de dinheiro</a></li>
 <li><a href="/cgi-bin/koha/reports/reserves_stats.pl">Reservas</a></li>
 </ul>

 [% IF plugins_enabled %]
 <h5>Plugins de relatórios</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=report">Plugins de relatórios</a></li>
 </ul>
 [% END %]

 <h5>Quadros de honra</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/bor_issues_top.pl">Leitores com mais empréstimos</a></li>
 <li><a href="/cgi-bin/koha/reports/cat_issues_top.pl">Documentos mais emprestados</a></li>
 </ul>

 <h5>Inactivo</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/borrowers_out.pl">Leitores que nunca requisitaram documentos</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_out.pl">Exemplares nunca emprestados</a></li>
 </ul>


 <h5>Outros</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/itemslost.pl">Exemplares perdidos</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Encomendas por fundo</a></li>
 <li><a href="/cgi-bin/koha/reports/manager.pl?report_name=itemtypes">Catálogo por tipo de documento</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_avg_stats.pl">Duração média do empréstimo</a></li>
 </ul>
 </div>
</div>
