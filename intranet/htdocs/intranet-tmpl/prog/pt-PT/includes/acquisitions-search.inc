<!-- acquisitions-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="supplier_search" role="tabpanel" class="tab-pane active">
 <form name="findsupplier" action="/cgi-bin/koha/acqui/booksellers.pl" method="post">
 <div class="form-title">
 <label class="control-label">Pesquisa de fornecedor</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="supplier" name="supplier" placeholder="Pesquisar fornecedores" type="text" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 <div id="orders_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/acqui/histsearch.pl" method="post">
 <div class="form-title">
 <label class="control-label">Pesquisa de encomendas</label>
 </div>

 <div class="form-content">
 <input class="form-control" id="title" name="title" placeholder="Título" size="13" type="text" value="[% title | html %]" />
 <input class="form-control" id="searchsupplier" name="name" placeholder="Fornecedor" size="13" type="text" value="[% name | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 <input type="hidden" id="do_search" name="do_search" value="do" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <div>
 <label for="basket" class="control-label">Cesto</label>
 <input class="form-control" id="basket" name="basket" placeholder="Cesto" type="text" />
 </div>
 <div>
 <label for="booksellerinvoicenumber" class="control-label">Número de factura</label>
 <input class="form-control" id="booksellerinvoicenumber" name="booksellerinvoicenumber" placeholder="Número de factura" type="text" />
 </div>
 <div>
 <a href="/cgi-bin/koha/acqui/histsearch.pl">Pesquisa avançada</a>
 </div>
 </div>
 </form>
 </div>
 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="supplier_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#supplier_search" role="tab" title="Pesquisa de fornecedor"><i class="fa fa-upload"></i> <span class="tab-title">Pesquisa de fornecedor</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="orders_search" class="keep_text" data-toggle="tab" href="#orders_search" role="tab" title="Pesquisa de encomendas"><i class="fa fa-download"></i> <span class="tab-title">Pesquisa de encomendas</span></a>
 </li>
 </ul>
</div><!-- /#header_search -->
<!-- /acquisitions-search.inc -->
