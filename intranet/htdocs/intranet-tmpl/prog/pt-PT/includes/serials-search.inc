[% USE Koha %]
<!-- serials-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="subscription_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/serials/serials-search.pl" method="get">
 [% IF ( routing ) %]
 <input type="hidden" name="routing" value="[% routing | html %]" />
 [% END %]
 <input type="hidden" name="searched" value="1" />

 <div class="form-title">
 <label class="control-label">Pesquisar assinaturas</label>
 </div>

 <div class="form-content">
 <input type="text" class="form-control" placeholder="ISSN" size="11" name="ISSN_filter" id="ISSN_filter" value="[% ISSN_filter | html %]" />

 [% IF (UNIMARC) %]
 <input type="text" class="form-control" placeholder="EAN" size="11" name="EAN_filter" id="EAN_filter" value="[% EAN_filter | html %]" />
 [% END %]

 <input class="form-control" id="title_filter" name="title_filter" placeholder="Título" size="11" type="text" value="[% title_filter | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>

 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 <div class="form-extra-content">
 <div>
 <label for="callnumber_filter">Cota:</label>
 <input class="form-control" id="callnumber_filter" name="callnumber_filter" placeholder="Cota" type="text" value="[% callnumber_filter | html %]">
 </div>
 <div>
 <label for="publisher_filter">Editor:</label>
 <input class="form-control" id="publisher_filter" name="publisher_filter" placeholder="Editor" type="text" value="[% publisher_filter | html %]">
 </div>
 <div>
 <label for="bookseller_filter">Fornecedor:</label>
 <input class="form-control" id="bookseller_filter" name="bookseller_filter" placeholder="Fornecedor" type="text" value="[% bookseller_filter | html %]">
 </div>
 <div>
 <a href="/cgi-bin/koha/serials/serials-search.pl">Pesquisa avançada</a>
 </div>
 </div> <!-- /.form-extra-content -->
 </form>
 </div> <!-- /#subscription_search -->

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="subscription_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#subscription_search" role="tab" title="Pesquisar assinaturas"><i class="fa fa-book"></i> <span class="tab-title">Pesquisar assinaturas</span></a>
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
<!-- /serials-search.inc -->
