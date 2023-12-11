[% USE Koha %]
<!-- patrons-admin-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="patron_category_search" role="tabpanel" class="tab-pane active">
 <form action="[% script_name | html %]" method="post">
 <div class="form-title">
 <label class="control-label">Pesquisar categorias de leitor</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" name="description" placeholder="Pesquisar pela categoria de leitor" type="text" value="[% searchfield | html %]" />
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

 </div> <!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="patron_category_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#patron_category_search" role="tab" title="Pesquisar categorias de leitor"><i class="fa fa-fw fa-id-card-o"></i> <span class="tab-title">Pesquisar categorias de leitor</span></a>
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
</div> <!-- /#header_search -->
<!-- /patrons-admin-search.inc -->
