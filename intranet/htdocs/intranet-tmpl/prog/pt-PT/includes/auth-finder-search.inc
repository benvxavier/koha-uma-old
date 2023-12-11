[% USE Koha %]
[% PROCESS 'form-blocks.inc' %]

<div id="toolbar" class="btn-toolbar">
 <div class="btn-group"><a href="#" id="clear" class="btn btn-default btn-sm"><i class="fa fa-trash"></i> Limpar campo</a></div>
 <div class="btn-group"><a href="#" id="createnew" class="btn btn-default btn-sm"><i class="fa fa-plus"></i> Criar nova autoridade</a></div>
</div>
<form name="f" method="get" action="auth_finder.pl">
 <input type="hidden" name="source" value="[% source | html %]" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="index" value="[% index | html %]" />
 <fieldset class="rows"><legend>Opções de pesquisa</legend>
 <ol><li>
 <span class="label">Tipo de autoridade: </span>
 [% authtypecode | html %]
 <input type="hidden" name="authtypecode" value="[% authtypecode | html %]" />
 </li>
 <li>
 <label for="mainmainentry">Pesquisar cabeçalho principal (apenas $a): </label>
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainmainentry">
 [% IF ( operator_mainstr == 'contains' ) %]
 <option value="contains" selected="selected">contem</option>
 [% ELSE %]
 <option value="contains">contem</option>
 [% END %]
 [% IF ( operator_mainstr == 'start' ) %]
 <option value="start" selected="selected">começa por</option>
 [% ELSE %]
 <option value="start">começa por</option>
 [% END %]
 [% IF ( operator_mainstr == 'exact' ) %]
 <option value="exact" selected="selected">é exactamente</option>
 [% ELSE %]
 <option value="exact">é exactamente</option>
 [% END %]
 </select>
 <input id="value_mainstr" style="width:400px;" type="text" name="value_mainstr" value="[% value_mainstr | html %]" />
 <div id="yvaluecontainermainmainentry"></div>
 </li>

 <li>
 <label for="mainentry">Pesquisar cabeçalho principal: </label>
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainentry">
 [% IF ( operator_main == 'contains' ) %]
 <option value="contains" selected="selected">contem</option>
 [% ELSE %]
 <option value="contains">contem</option>
 [% END %]
 [% IF ( operator_main == 'start' ) %]
 <option value="start" selected="selected">começa por</option>
 [% ELSE %]
 <option value="start">começa por</option>
 [% END %]
 [% IF ( operator_main == 'exact' ) %]
 <option value="exact" selected="selected">é exactamente</option>
 [% ELSE %]
 <option value="exact">é exactamente</option>
 [% END %]
 </select>
 <input id="value_main" style="width:400px;" type="text" name="value_main" value="[% value_main | html %]" />
 <div id="yvaluecontainermainentry"></div>
 </li>
 <li>
 <label for="marclistheading">Pesquisar todos os cabeçalhos: </label>
 <input type="hidden" name="marclist" value="match" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistheading">
 [% IF ( operator_match == 'contains' ) %]
 <option value="contains" selected="selected">contem</option>
 [% ELSE %]
 <option value="contains">contem</option>
 [% END %]
 [% IF ( operator_match == 'start' ) %]
 <option value="start" selected="selected">começa por</option>
 [% ELSE %]
 <option value="start">começa por</option>
 [% END %]
 [% IF ( operator_match == 'exact' ) %]
 <option value="exact" selected="selected">é exactamente</option>
 [% ELSE %]
 <option value="exact">é exactamente</option>
 [% END %]
 </select>
 <input type="text" name="value_match" value="[% value_match | html %]" />
 </li>
 <li>
 <label for="marclistanywhere">Pesquisar todo o registo: </label>
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistanywhere">
 [% IF ( operator_any == 'contains' ) %]
 <option value="contains" selected="selected">contem</option>
 [% ELSE %]
 <option value="contains">contem</option>
 [% END %]
 [% IF ( operator_any == 'start' ) %]
 <option value="start" selected="selected">começa por</option>
 [% ELSE %]
 <option value="start">começa por</option>
 [% END %]
 [% IF ( operator_any == 'exact' ) %]
 <option value="exact" selected="selected">é exactamente</option>
 [% ELSE %]
 <option value="exact">é exactamente</option>
 [% END %]
 </select>
 <input id="value_any" style="width:400px;" type="text" name="value_any" value="[% value_any | html %]" />
 <div id="yvaluecontainermarclist"></div>
 </li>
 <li>
 <label for="orderby">Ordenar por: </label>
 <select name="orderby" id="orderby">
 [% IF ( orderby == 'HeadingAsc' ) %]
 <option value="HeadingAsc" selected="selected">Entradas A-Z</option>
 [% ELSE %]
 <option value="HeadingAsc">Entradas A-Z</option>
 [% END %]
 [% IF ( orderby == 'HeadingDsc' ) %]
 <option value="HeadingDsc" selected="selected">Entradas Z-A</option>
 [% ELSE %]
 <option value="HeadingDsc">Entradas Z-A</option>
 [% END %]
 [% IF ( orderby == '' && op ) %]
 <option value="" selected="selected">Nenhum</option>
 [% ELSE %]
 <option value="">Nenhum</option>
 [% END %]
 </select>
 </li></ol></fieldset>
 [% IF source == 'auth' %]
 <fieldset class="rows"><legend>Informação de relação</legend>
 <ol>
 <li>
 <label for="relationship">Relação especial: </label>
 <select name="relationship" id="relationship">
 [% selected=relationship | html %] [% PROCESS selectoptionopen value='' %]Nenhuma especificada</option>
 [% IF Koha.Preference('marcflavour') == 'MARC21' %] [% PROCESS selectoptionopen value='a' %]a - Cabeçalho inicial</option>
 [% PROCESS selectoptionopen value='b' %]b - Cabeçalho final</option>
 [% PROCESS selectoptionopen value='d' %]d - Acrónimo</option>
 [% PROCESS selectoptionopen value='f' %]f - Composição musical</option>
 [% PROCESS selectoptionopen value='g' %]g - Termo mais abrangente</option>
 [% PROCESS selectoptionopen value='h' %]h - Termo mais estrito</option>
 [% PROCESS selectoptionopen value='i' %]i - Frase referência de instrução no subcampo $i</option>
 [% PROCESS selectoptionopen value='n' %]n - Não aplicável</option>
 [% PROCESS selectoptionopen value='r' %]r - Designação de relação no $i ou $4</option>
 [% PROCESS selectoptionopen value='t' %]t - Corpo do parente imediato</option>
 [% ELSIF Koha.Preference('marcflavour') == 'UNIMARC' %] [% PROCESS selectoptionopen value='a' %]a = nome inicial</option>
 [% PROCESS selectoptionopen value='b' %]b = nome posterior</option>
 [% PROCESS selectoptionopen value='c' %]c = nome oficial</option>
 [% PROCESS selectoptionopen value='d' %]d = acrónimo / inicial / abreviatura</option>
 [% PROCESS selectoptionopen value='e' %]e = pseudónimo</option>
 [% PROCESS selectoptionopen value='f' %]f = nome real</option>
 [% PROCESS selectoptionopen value='g' %]g = termo ou nome mais abrangente</option>
 [% PROCESS selectoptionopen value='h' %]h = termo ou nome mais restrito</option>
 [% PROCESS selectoptionopen value='i' %]i = nome religioso</option>
 [% PROCESS selectoptionopen value='j' %]j = nome de casado</option>
 [% PROCESS selectoptionopen value='k' %]k = nome antes do casamento</option>
 [% PROCESS selectoptionopen value='l' %]l = pseudónimo partilhado</option>
 [% PROCESS selectoptionopen value='m' %]m = nome secular</option>
 [% PROCESS selectoptionopen value='n' %]n = diferente forma de um nome</option>
 [% PROCESS selectoptionopen value='o' %]o = nome atribuído / título convencional de um trabalho</option>
 [% PROCESS selectoptionopen value='x' %]x = não aplicável</option>
 [% PROCESS selectoptionopen value='z' %]z = outro</option>
 [% END %]
 </select>
 </li>
 </ol>
 </fieldset>
 [% END %]
 <fieldset class="action"> <input class="submit" id="search" type="submit" value="Pesquisar" /> <a id="cancel" class="cancel close" href="#">Anular</a>
 </fieldset>
</form>
