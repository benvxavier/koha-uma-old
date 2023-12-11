[% USE Koha %]
<!-- z3950-admin-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="z3950_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/admin/z3950servers.pl" method="post">
 <div class="form-title">
 <label class="control-label">Procurar servidores Z39.50/SRU</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchfield" name="searchfield" placeholder="Pesquisar servidor Z39.50/SRU" type="text" value="[% searchfield | html %]" />
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="z3950_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#z3950_search" role="tab" title="Procurar servidores Z39.50/SRU"><i class="fa fa-search"></i> <span class="tab-title">Procurar servidores Z39.50/SRU</span></a>
 </li>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation">
 <a aria-controls="circ_search" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Emprestar"><i class="fa fa-upload"></i> <span class="tab-title">Emprestar</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a aria-controls="catalog_search" class="keep_text" data-toggle="tab" href="#catalog_search" role="tab" title="Pesquisar no catálogo"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Pesquisar no catálogo</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- /z3950-admin-search.inc -->
