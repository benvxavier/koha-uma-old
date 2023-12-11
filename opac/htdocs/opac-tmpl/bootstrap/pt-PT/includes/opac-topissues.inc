[% USE Koha %]
[% USE Branches %]
[% PROCESS 'html_helpers.inc' %]

<div id="search-facets">
 <form method="get" action="/cgi-bin/koha/opac-topissues.pl">
 <h2><a href="#" class="menu-collapse-toggle">Refinar a pesquisa</a></h2>
 <ul class="menu-collapse">
 <li><label for="limit">Mostrar o topo </label>
 <select name="limit" id="limit">
 [% IF ( limit == 10 ) %]<option value ="10" selected="selected">10 títulos</option>[% ELSE %]<option value="10">10 títulos</option>[% END %]
 [% IF ( limit == 15 ) %]<option value ="15" selected="selected">15 títulos</option>[% ELSE %]<option value="15">15 títulos</option>[% END %]
 [% IF ( limit == 20 ) %]<option value ="20" selected="selected">20 títulos</option>[% ELSE %]<option value="20">20 títulos</option>[% END %]
 [% IF ( limit == 30 ) %]<option value ="30" selected="selected">30 títulos</option>[% ELSE %]<option value="30">30 títulos</option>[% END %]
 [% IF ( limit == 40 ) %]<option value ="40" selected="selected">40 títulos</option>[% ELSE %]<option value="40">40 títulos</option>[% END %]
 [% IF ( limit == 50 ) %]<option value ="50" selected="selected">50 títulos</option>[% ELSE %]<option value="50">50 títulos</option>[% END %]
 [% IF ( limit == 100 ) %]<option value ="100" selected="selected">100 títulos</option>[% ELSE %]<option value="100">100 títulos</option>[% END %]
 </select></li>

 [% IF Branches.all.size > 1 %]
 <li><label for="branch">De: </label>
 <select name="branch" id="branch">
 <option value="">Todas as bibliotecas</option>
 [% PROCESS options_for_libraries libraries => Branches.all( selected => branch ) %]
 </select></li>
 [% END %]

 [% OpacAdvancedSearchTypes = Koha.Preference('OpacAdvancedSearchTypes').split('\|') %]
 [% IF OpacAdvancedSearchTypes.grep('^itemtypes$').size %]
 <li>
 <label for="itemtype">Limitar a: </label>
 <select name="itemtype" id="itemtype">
 <option value="">Todos tipos de documento</option>
 [% FOREACH itemtype IN ItemTypes.Get() %]
 [% IF itemtype.itemtype == selected_itemtype %]
 <option value="[% itemtype.itemtype | html %]" selected="selected">
 [% ELSE %]
 <option value="[% itemtype.itemtype | html %]">
 [% END %]
 [% itemtype.translated_description | html %]
 </option>
 [% END %]
 </select>
 </li>
 [% END %]

 [% IF OpacAdvancedSearchTypes.grep('^ccode$').size %]
 <li>
 <label for="ccode">Limitar a:</label>
 <select name="ccode" id="ccode">
 <option value="">Todas as coleções</option>
 [% FOREACH ccode IN AuthorisedValues.Get('CCODE', 1) %]
 [% IF ccode.authorised_value == selected_ccode %]
 <option value="[% ccode.authorised_value | html %]" selected="selected">
 [% ELSE %]
 <option value="[% ccode.authorised_value | html %]">
 [% END %]
 [% ccode.lib | html %]
 </option>
 [% END %]
 </select>
 </li>
 [% END %]

 <li><label for="timeLimit">Documentos adquiridos por último:</label>
 <select name="timeLimit" id="timeLimit">
 [% IF ( timeLimit == 3 ) %]
 <option value="3" selected="selected">3 meses</option>
 [% ELSE %]
 <option value="3">3 meses</option>
 [% END %]
 [% IF ( timeLimit == 6 ) %]
 <option value="6" selected="selected">6 meses</option>
 [% ELSE %]
 <option value="6">6 meses</option>
 [% END %]
 [% IF ( timeLimit == 12 ) %]
 <option value="12" selected="selected">12 meses</option>
 [% ELSE %]
 <option value="12">12 meses</option>
 [% END %]
 [% IF ( timeLimit == 999 ) %]
 <option value="999" selected="selected">Sem limite</option>
 [% ELSE %]
 <option value="999">Sem limite</option>
 [% END %]
 </select></li>
 <li>
 <input type="hidden" name="do_it" value="1" />
 <input class="btn btn-primary" type="submit" value="Submeter" />
 </li>
 </ul>
 </form>
</div>
