<fieldset class="acqui_basket_add">
 <legend class="sr-only">Adicionar encomenda ao cesto</legend>
 [% IF has_budgets %]
 <ul>
 <li>
 <form action="/cgi-bin/koha/catalogue/search.pl" method="get">
 <label>A partir de um registo existente: <input type="text" name="q" size="25" />
 </label>
 <input class="submit" data-basketno="[% basketno | html %]" data-booksellerid="[% booksellerid | html %]" id="searchtoorder" type="submit" value="Submeter" />
 </form>
 </li>
 <li><a href="/cgi-bin/koha/acqui/newordersuggestion.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">A partir de uma sugestão</a></li>
 <li><a href="/cgi-bin/koha/acqui/newordersubscription.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">De uma assinatura</a></li>
 <li><a href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">A partir de um registo novo (vazio)</a></li>
 <li><a href="/cgi-bin/koha/acqui/duplicate_orders.pl?basketno=[% basketno | uri %]">A partir de encomendas existentes (cópia)</a></li>
 <li><a href="/cgi-bin/koha/acqui/z3950_search.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">A partir de uma fonte externa</a></li>
 [% IF ( CAN_user_tools_stage_marc_import ) %]<li><a href="/cgi-bin/koha/tools/stage-marc-import.pl?basketno=[% basketno | uri %]&amp;booksellerid=[% booksellerid | uri %]"> A partir de um novo ficheiro</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/addorderiso2709.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]"> A partir de um ficheiro</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/reserveratios.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">A partir de títulos com rácios de reserva elevados</a></li>[% END %]
 </ul>
 [% ELSE %]
 <div class="dialog alert">
 <p>Não pode criar nenhuma encomenda sem que primeiro <a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">definir um orçamento e um fundo</a>.</p>
 </div>
 [% END %]
</fieldset>
