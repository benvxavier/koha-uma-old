[% USE HtmlId %]
<div id="menu">
 <ul>
 [% IF ( accounting ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="Contabilidade">Contabilidade</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="Contabilidade">Contabilidade</a>
 [% END %]
 [% IF ( acquisitions ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Aquisições">Aquisições</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Aquisições">Aquisições</a>
 [% END %]
 </li>

 [% IF ( admin ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="Administração">Administração</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="Administração">Administração</a>
 [% END %]
 </li>

 [% IF ( authorities ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="Controlo de autoridade">Autoridades</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="Controlo de autoridade">Autoridades</a>
 [% END %]
 </li>

 [% IF ( cataloguing ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="Catalogar">Catalogar</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="Catalogar">Catalogar</a>
 [% END %]
 </li>

 [% IF ( circulation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Empréstimo">Empréstimo</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Empréstimo">Empréstimo</a>
 [% END %]
 </li>

 [% IF ( enhanced_content ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Configurações da gestão de conteúdos">Gestão de conteúdos</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Configurações da gestão de conteúdos">Gestão de conteúdos</a>
 [% END %]
 </li>

 [% IF ( erm ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="Gestão de recursos electrónicos">Gestão de recursos electrónicos</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="Gestão de recursos electrónicos">Gestão de recursos electrónicos</a>
 [% END %]
 </li>

 [% IF ( i18n_l10n ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Regionalização e localização">Regionalização</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Regionalização e localização">Regionalização</a>
 [% END %]
 </li>

 [% IF ( interlibrary_loans ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="Empréstimos inter-bibliotecas">Empréstimos inter-bibliotecas</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="Empréstimos inter-bibliotecas">Empréstimos inter-bibliotecas</a>
 [% END %]
 </li>

 [% IF ( local_use ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Uso local</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Uso local</a>
 [% END %]
 </li>

 [% IF ( logs ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Logs de transações">Logs</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Logs de transações">Logs</a>
 [% END %]
 </li>

 [% IF ( opac ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="Catálogo Público em Linha (OPAC)">OPAC</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="Catálogo Público em Linha (OPAC)">OPAC</a>
 [% END %]
 </li>

 [% IF ( patrons ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Leitores">Leitores</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Leitores">Leitores</a>
 [% END %]
 </li>

 [% IF ( searching ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="Pesquisa">Pesquisa</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="Pesquisa">Pesquisa</a>
 [% END %]
 </li>

 [% IF ( serials ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Periódicos">Periódicos</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Periódicos">Periódicos</a>
 [% END %]
 </li>

 [% IF ( staff_interface ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="Interface dos técnicos">Interface dos técnicos</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="Interface dos técnicos">Interface dos técnicos</a>
 [% END %]
 </li>

 [% IF ( tools ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Ferramentas">Ferramentas</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Ferramentas">Ferramentas</a>
 [% END %]
 </li>

 [% IF ( web_services ) %]
 <li class="active">
 <a title="Web services" href="/cgi-bin/koha/admin/preferences.pl?tab=web_services">Web services</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Web services" href="/cgi-bin/koha/admin/preferences.pl?tab=web_services">Web services</a>
 [% END %]
 </li>
 </ul>
</div>

[% BLOCK subtabs %]
 [% UNLESS ( searchfield ) %]
 [% FOREACH TAB IN TABS %]
 <ul>
 [% FOREACH LINE IN TAB.LINES %]
 [% IF ( LINE.is_group_title ) %]
 <li><a class="pref_sublink" href="#[% TAB.tab_id | html %]_[% LINE.title | $HtmlId %]">[% LINE.title | html %]</a></li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 [% END %]
[% END %]
