[% INCLUDE 'blocking_errors.inc' %]
[% IF ( authid || CAN_user_editauthorities) %]

 <div id="toolbar" class="btn-toolbar">
 [% IF ( CAN_user_editauthorities ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">
 <i class="fa fa-plus"></i> Nova autoridade <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
 [% FOREACH authority_type IN authority_types %]
 <li><a href="/cgi-bin/koha/authorities/authorities.pl?authtypecode=[% authority_type.authtypecode | uri %]">[% authority_type.authtypetext | html %]</a></li>
 [% END %]
 </ul>
 </div>
 [% IF servers.count > 0 %]
 <div class="btn-group">
 <button id="z3950_new" class="btn btn-default">
 <i class="fa fa-search"></i> Novo a partir de Z39.50/SRU </button>
 </div>
 [% END %]
 [% END %]

 [% IF ( authid ) %]
 [% IF ( CAN_user_editauthorities ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">
 <i class="fa fa-pencil"></i> Alterar <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
 <li><a id="editAuth" href="/cgi-bin/koha/authorities/authorities.pl?authid=[% authid | html %]">Modificar o registo</a></li>
 <li><a id="dupAuth" href="/cgi-bin/koha/authorities/authorities.pl?authid=[% authid | html %]&amp;op=duplicate">Editar como novo (duplicado)</a></li>
 [% IF servers.count > 0 %]
 <li><a id="z3950_replace" href="#">Substituir registo via Z39.50/SRU</a></li>
 [% END %]
 [% UNLESS ( count ) %]
 <li><a href="#" id="delAuth">Eliminar o registo</a></li>
 [% END %]
 </ul>
 </div>
 [% END %]

 <div class="btn-group">
 <a class="btn btn-default dropdown-toggle" data-toggle="dropdown" href="#"><i class="fa fa-download"></i> Guardar <span class="caret"></span>
 </a>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/authorities/export.pl?format=mads&amp;op=export&amp;authid=[% authid | uri %]">MADS (XML)</a></li>
 <li><a href="/cgi-bin/koha/authorities/export.pl?format=marcxml&amp;op=export&amp;authid=[% authid | uri %]">MARCXML</a></li>
 <li><a href="/cgi-bin/koha/authorities/export.pl?format=marc8&amp;op=export&amp;authid=[% authid | uri %]">MARC (non-Unicode/MARC-8)</a></li>
 <li><a href="/cgi-bin/koha/authorities/export.pl?format=utf8&amp;op=export&amp;authid=[% authid | uri %]">MARC (Unicode/UTF-8)</a></li>
 </ul>
 </div>
 [% END %]
 </div>

[% END %]
