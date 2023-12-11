[% USE Branches %]
[% USE Registers %]
<div id="navmenu">
 <div id="navmenulist">
 [% IF ( CAN_user_cash_management_cashup || CAN_user_cash_management_anonymous_refund ) %]
 <h5>Gestão do dinheiro</h5>
 <ul>
 <li><a href="/cgi-bin/koha/pos/pay.pl">Ponto de venda</a></li>
 [% IF !(Registers.session_register_name == '') %]
 <li><a href="/cgi-bin/koha/pos/register.pl">Histórico de transações para [% Registers.session_register_name | html %]</a></li>
 [% END %]
 <li><a href="/cgi-bin/koha/pos/registers.pl">Resumo de contabilidade de [% Branches.GetLoggedInBranchname | html %]</a></li>
 </ul>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cash_registers || CAN_user_parameters_manage_accounts) %]
 <h5>Administração</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">Configurar as caixas registadoras</a></li>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">Configurar exemplares para compra</a></li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
