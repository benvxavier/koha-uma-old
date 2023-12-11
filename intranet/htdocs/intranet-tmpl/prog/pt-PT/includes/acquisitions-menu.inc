[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>Aquisições</h5>
 <ul>
 <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">Aquisições (início)</a></li>
 [% IF ( CAN_user_acquisition_order_receive ) %]<li><a href="/cgi-bin/koha/acqui/lateorders.pl">Encomendas em atraso</a></li>[% END %]
 [% IF ( CAN_user_suggestions_suggestions_manage ) %]<li><a href="/cgi-bin/koha/suggestion/suggestion.pl">Sugestões</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl">Facturas</a></li>
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/acqui/edifactmsgs.pl">Mensagens EDIFACT</a></li>
 [% END %]
 </ul>
 [% IF ( CAN_user_reports || CAN_user_circulate_circulate_remaining_permissions ) %]
 <h5>Relatórios</h5>
 <ul>
 [% IF ( CAN_user_reports ) %]
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Wizard de estatísticas das aquisições</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Encomendas por fundo</a></li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li><a href="/cgi-bin/koha/circ/reserveratios.pl">Rácios da reserva</a></li>
 [% END %]
 </ul>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || CAN_user_acquisition_currencies_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) || CAN_user_parameters_manage_additional_fields ) %]
 <h5>Administração</h5>
 <ul>
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Orçamentos</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Fundos</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Divisas</a></li>
 [% END %]
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">Contas EDI</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">EANs</a></li>
 [% END %]
 [% IF CAN_user_acquisition_edit_invoices && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqinvoices">Gerir campos da fatura</a>
 </li>
 [% END %]
 [% IF CAN_user_acquisition_order_manage && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqbasket">Gerir os campos da encomenda</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqorders">Gerir os campos da encomenda</a>
 </li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
