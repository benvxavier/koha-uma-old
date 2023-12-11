[% USE Koha %]
<div id="navmenu">
<div id="navmenulist">

<h5>Executar relatórios</h5>
<ul>
 [% IF ( CAN_user_reports_execute_reports ) %]<li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Use%20saved">Relatórios guardados</a></li>[% END %]
</ul>
<h5>Dicionário dos relatórios</h5>
<ul>
<li><a href="/cgi-bin/koha/reports/dictionary.pl?phase=View%20Dictionary">Ver dicionário</a></li>
</ul>
<h5>Recursos úteis</h5>
<ul>
<li><a href="http://wiki.koha-community.org/wiki/SQL_Reports_Library" target="blank">Repositório de relatórios</a></li>
[% SET koha_version = Koha.Version %]
[% IF koha_version.development %]
 <li><a href="http://schema.koha-community.org/master" target="blank">Esquema da base de dados do Koha</a></li>
[% ELSE %]
 <li><a href="http://schema.koha-community.org/[% koha_version.major | uri %]_[% koha_version.minor | uri %]" target="blank">Esquema da base de dados do Koha</a></li>
[% END %]
</ul>
</div>
</div>
