[% USE Koha %]
<!-- erm-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="agreement_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/erm/agreements" method="get">
 <div class="form-title">
 <label class="control-label">Pesquisar contrato</label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="agreement_filter" name="q" placeholder="Palavras a pesquisar" size="40" type="text" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 <div id="license_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/erm/licenses" method="get">
 <div class="form-title">
 <label class="control-label">Pesquisa de licenças</label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="license_filter" name="q" placeholder="Palavras a pesquisar" size="40" type="text" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 <div id="package_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/erm/eholdings/local/packages" method="get">
 <div class="form-title">
 <label class="control-label">Pesquisa de pacote</label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="package_name_filter" name="package_name" placeholder="Palavras a pesquisar" size="40" type="text" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 <div id="title_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/erm/eholdings/local/titles" method="get">
 <div class="form-title">
 <label class="control-label">Pesquisar título</label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="title_filter" name="publication_title" placeholder="Palavras a pesquisar" size="40" type="text" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>
 </div><!-- /.tab-content -->

 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="agreement_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#agreement_search" id="agreement_search_tab" role="tab" title="Pesquisar contratos"><i class="fa fa-check-circle-o"></i> <span class="tab-title">Pesquisar contratos</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="license_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#license_search" id="license_search_tab" role="tab" title="Pesquisa de licenças"><i class="fa fa-gavel"></i> <span class="tab-title">Pesquisa de licenças</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="package_search" class="keep_text" data-toggle="tab" href="#package_search" id="package_search_tab" role="tab" title="Pesquisar pacotes"><i class="fa fa-archive"></i> <span class="tab-title">Pesquisar pacotes</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="title_search" class="keep_text" data-toggle="tab" href="#title_search" id="title_search_tab" role="tab" title="Pesquisar títulos"><i class="fa fa-sort-alpha-asc"></i> <span class="tab-title">Pesquisar títulos</span></a>
 </li>
 </ul>
</div><!-- /#header_search -->
<!-- /erm-search.inc -->
