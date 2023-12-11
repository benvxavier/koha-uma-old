<!-- authorities-search.inc -->

[% BLOCK orderby %]
 <div>
 <label class="control-label">
 Ordenar por <select name="orderby" class="form-control">
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
 </label>
 </div>
[% END %]

[% BLOCK operator %]
 <div>
 <label class="control-label">
 Operador <select name="operator" class="form-control">
 [% IF ( operator == 'contains' ) %]
 <option value="contains" selected="selected">contem</option>
 [% ELSE %]
 <option value="contains">contem</option>
 [% END %]
 [% IF ( operator == 'start' ) %]
 <option value="start" selected="selected">começa por</option>
 [% ELSE %]
 <option value="start">começa por</option>
 [% END %]
 [% IF ( operator == 'exact' ) %]
 <option value="exact" selected="selected">é exactamente</option>
 [% ELSE %]
 <option value="exact">é exactamente</option>
 [% END %]
 </select>
 </label>
 </div>
[% END %]

[% BLOCK authtype %]
 <div>
 <label>
 Tipo de autoridade <select name="authtypecode" class="form-control">
 [% IF (marcflavour == 'UNIMARC' ) %]<option value="">Todos tipos de autoridade</option>[% END %]
 [% FOREACH authority_type IN authority_types %]
 [% IF authority_type.authtypecode == authtypecode %]
 <option value="[% authority_type.authtypecode | html %]" selected="selected">[% authority_type.authtypetext | html %]</option>
 [% ELSE %]
 <option value="[% authority_type.authtypecode | html %]">[% authority_type.authtypetext | html %]</option>
 [% END %]
 [% END %]
 </select>
 </label>
 </div>
[% END %]

<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="mainmain_heading" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />

 <div class="form-title">
 <label class="control-label">Pesquisar cabeçalho principal (apenas $a)</label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_mainentry" name="value" placeholder="Pesquisar cabeçalho principal (apenas $a)" type="text" value="[% value | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 <div id="main_heading" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />

 <div class="form-title">
 <label class="control-label">Pesquisar entrada principal</label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_mainheading" name="value" placeholder="Pesquisar entrada principal" type="text" value="[% value | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 <div id="matchheading_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="match" />

 <div class="form-title">
 <label class="control-label">Pesquisar todos os campos</label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_matchheading" name="value" placeholder="Pesquisar qualquer cabeçalho" type="text" value="[% value | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 <div id="entire_record" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />

 <div class="form-title">
 <label class="control-label">Pesquisar todo o registo</label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_anywhere" name="value" placeholder="Pesquisar qualquer campo de autoridade" type="text" value="[% value | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="mainmain_heading" aria-expanded="true" class="keep_text" data-toggle="tab" href="#mainmain_heading" role="tab" title="Pesquisar cabeçalho principal (apenas $a)"><i style="font-weight:bold">$a</i> <span class="tab-title">Cabeçalho principal (apenas $a)</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="main_heading" class="keep_text" data-toggle="tab" href="#main_heading" role="tab" title="Pesquisar entrada principal"><i class="fa fa-header"></i> <span class="tab-title">Cabeçalho principal</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="matchheading_search" class="keep_text" data-toggle="tab" href="#matchheading_search" role="tab" title="Pesquisar todos os campos"><i class="fa fa-align-center"></i> <span class="tab-title">Todos os cabeçalhos</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="entire_record" class="keep_text" data-toggle="tab" href="#entire_record" role="tab" title="Pesquisar todo o registo"><i class="fa fa-folder-open-o"></i> <span class="tab-title">Registo inteiro</span></a>
 </li>
 <li role="presentation">
 </ul>
</div><!-- /#header_search -->
<!-- /authorities-search.inc -->
