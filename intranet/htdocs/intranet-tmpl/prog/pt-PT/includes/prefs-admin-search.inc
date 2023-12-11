<!-- prefs-admin-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="syspref_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/admin/preferences.pl">
 <input type="hidden" name="tab" value="[% last_tab | html %]" />
 <input type="hidden" name="op" value="search" />

 <div class="form-title">
 <label class="control-label">Pesquisar preferências do sistema</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchfield" name="searchfield" placeholder="Pesquisar preferências do sistema" type="text" value="">
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
 <a aria-controls="syspref_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#syspref_search" role="tab" title="Pesquisar preferências do sistema"><i class="fa fa-fw fa-cogs"></i> <span class="tab-title">Pesquisar preferências do sistema</span></a>
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
<!-- /prefs-admin-search.inc -->
