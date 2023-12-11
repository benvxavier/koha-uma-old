
[% USE Koha %]
<div id="header_search" role="tablist">
 <div class="tab-content">

 <div id="suggestions_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/acqui/newordersuggestion.pl" method="get">
 <input type="hidden" name="booksellerid" value="[% booksellerid | html %]" />

 <div class="form-title">
 <label class="control-label">Pesquisar sugestões</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchtitle" name="title" placeholder="Título" size="10" type="text" value="[% title | html %]" />
 <input class="head-searchbox form-control" id="searchauthor" name="author" placeholder="Autor" size="10" type="text" value="[% author | html %]" />
 <input class="head-searchbox form-control" id="searchpublishercode" name="publishercode" placeholder="Editor" size="10" type="text" value="[% publishercode | html %]" />
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
 <a aria-expanded="true" class="keep_text" data-toggle="tab" href="#suggestions_search" role="tab" title="Pesquisar sugestões"><i class="fa fa-comment-o"></i> <span class="tab-title">Pesquisar sugestões</span></a>
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
<!-- /suggestions-add-search.inc -->
