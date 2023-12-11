[% USE Context %]
[% INCLUDE 'blocking_errors.inc' %]
<div id="toolbar" class="btn-toolbar">

[% IF ( CAN_user_editcatalogue_edit_catalogue || CAN_user_editcatalogue_edit_items || CAN_user_serials_create_subscription || Koha.Preference('CatalogConcerns') ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Novo <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a id="newbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl">Novo registo</a></li>
 [% END %]

 [% IF ( CAN_user_editcatalogue_edit_items ) %]
 <li><a id="newitem" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber | html %]#additema">Novo exemplar</a></li>
 [% END %]
 [% IF ( CAN_user_serials_create_subscription ) %]
 <li><a id="newsub" href="/cgi-bin/koha/serials/subscription-add.pl?biblionumber_for_new_subscription=[% biblionumber | html %]">Nova assinatura</a></li>
 [% END %]

 [% IF ( EasyAnalyticalRecords && CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% biblionumber | uri %]&amp;analyze=1">Analizar exemplares</a></li>
 [% END %]
 [% IF CAN_user_editcatalogue_edit_catalogue && ! EasyAnalyticalRecords %]
 <li><a href="/cgi-bin/koha/cataloguing/addbiblio.pl?parentbiblionumber=[% biblionumber | uri %]">Novo registo filho</a></li>
 [% END %]
 [% IF Koha.Preference('CatalogConcerns') %]
 <li><a id="newconcern" role="button" href="#" data-toggle="modal" data-target="#addConcernModal">Novo problema de catalogação</a></li>
 [% END %]
 </ul>
 </div>
[% END %]

[% IF ( CAN_user_editcatalogue_edit_catalogue || CAN_user_editcatalogue_edit_items || CAN_user_tools_items_batchmod || CAN_user_tools_items_batchdel ) or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-pencil"></i> Alterar <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% IF CAN_user_editcatalogue_edit_catalogue or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 <li><a id="editbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber | html %]">Modificar o registo</a></li>
 [% END %]

 [% IF CAN_user_tools_records_batchmod %]
 <li><a id="modifybiblio" href="/cgi-bin/koha/tools/batch_record_modification.pl?recordtype=biblio&op=list&recordnumber_list=[% biblionumber | html %]">Modificar registo usando o modelo</a></li>
 [% END %]

 [% IF CAN_user_editcatalogue_edit_items or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 <li><a id="edititems" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber | html %]">Editar exemplares</a></li>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod ) %]
 [% IF ( count ) %]
 <li><a id="batchedit" href="/cgi-bin/koha/tools/batchMod.pl?op=show&amp;biblionumber=[% biblionumber | html %]&amp;src=CATALOGUING">Modificar exemplares em lote</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="batchedit-disabled" title="O registo não possui exemplares">Modificar exemplares em lote</a></li>
 [% END %]
 [% END %]

 [% IF ( CAN_user_tools_items_batchdel ) %]
 [% IF ( count ) %]
 <li><a id="batchdelete" href="/cgi-bin/koha/tools/batchMod.pl?del=1&amp;op=show&amp;biblionumber=[% biblionumber | html %]&amp;src=CATALOGUING">Eliminar exemplares em lote</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="batchdelete-disabled" title="O registo não possui exemplares">Eliminar exemplares em lote</a></li>
 [% END %]
 [% END %]

 [% IF ( CAN_user_editcatalogue_edit_items ) %]<li><a href="/cgi-bin/koha/cataloguing/moveitem.pl?biblionumber=[% biblionumber | uri %]">Associar exemplar</a></li>[% END %]

 [% IF ( EasyAnalyticalRecords ) %][% IF ( CAN_user_editcatalogue_edit_items ) %]<li><a href="/cgi-bin/koha/cataloguing/linkitem.pl?biblionumber=[% biblionumber | uri %]">Ligação para exemplar</a>[% END %][% END %]
 [% IF ( LocalCoverImages || OPACLocalCoverImages) %][% IF ( CAN_user_tools_upload_local_cover_images ) %]<li><a href="/cgi-bin/koha/tools/upload-cover-image.pl?biblionumber=[% biblionumber | uri %]&amp;filetype=image">Carregar imagem</a>[% END %][% END %]

 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a id="duplicatebiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber | html %]&amp;op=duplicate">Editar como novo (duplicado)</a></li>
 <li><a href="#" id="z3950copy">Substituir registo via Z39.50/SRU</a></li>
 [% END %]

 [% IF CAN_user_editcatalogue_edit_catalogue or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 [% IF ( count ) %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deletebiblio" title="[% count | html %] exemplar(es) associado(s) ao registo. Deve eliminar todos os exemplares antes de eliminar o registo.">Eliminar o registo</a></li>
 [% ELSIF ( biblio.subscriptions.count ) %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deletebiblio" title="[% biblio.subscriptions.count | html %] assinatura(s) associada(s) ao registo. Deve eliminar todas as assinaturas antes de eliminar o registo.">Eliminar o registo</a></li>
 [% ELSE %]
 <li><a id="deletebiblio" data-order-manage="[% CAN_user_acquisition_order_manage | html %]" href="#">Eliminar o registo</a></li>
 [% END %]
 [% END %]

 [% IF CAN_user_editcatalogue_delete_all_items or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 [% IF ( count ) %]
 <li><a href="#" id="deleteallitems">Eliminar todos os itens</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deleteallitems-disabled" title="O registo não possui exemplares">Eliminar todos os itens</a></li>
 [% END %]
 [% END %]

 </ul>
 </div>
[% END %]

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-download"></i> Guardar <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=bibtex&amp;op=export&amp;bib=[% biblionumber | uri %]">BIBTEX</a></li>
 <li><a href="#" data-toggle="modal" data-target="#exportModal_">Dublin Core</a></li>
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=marcxml&amp;op=export&amp;bib=[% biblionumber | uri %]">MARCXML</a></li>
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=marc8&amp;op=export&amp;bib=[% biblionumber | uri %]">MARC (non-Unicode/MARC-8)</a></li>
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=utf8&amp;op=export&amp;bib=[% biblionumber | uri %]">MARC (Unicode/UTF-8)</a></li>
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=marcstd&amp;op=export&amp;bib=[% biblionumber | uri %]">MARC (Unicode/UTF-8, omissão)</a></li>
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=mods&amp;op=export&amp;bib=[% biblionumber | uri %]">MODS (XML)</a></li>
 <li><a href="/cgi-bin/koha/catalogue/export.pl?format=ris&amp;op=export&amp;bib=[% biblionumber | uri %]">RIS</a></li>
 </ul>
 </div>

 [% IF (Koha.Preference("intranetbookbag")) %]
 [% IF ( incart ) %]
 <div class="btn-group">
 <a id="cart[% biblionumber | html %]" class="btn btn-default addtocart incart" href="#"><i class="fa fa-shopping-cart"></i> Adicionar ao carrinho</a>
 </div>
 <div class="btn-group">
 <a id="cartR[% biblionumber | html %]" class="btn btn-default cartRemove incart" href="#"><i class="fa fa-shopping-cart"></i> Remover do carrinho</a>
 </div>
 [% ELSE %]
 <div class="btn-group">
 <a id="cart[% biblionumber | html %]" class="btn btn-default addtocart" href="#"><i class="fa fa-shopping-cart"></i> Adicionar ao carrinho</a>
 </div>
 <div class="btn-group">
 <a id="cartR[% biblionumber | html %]" class="btn btn-default cartRemove" href="#"><i class="fa fa-shopping-cart"></i> Remover do carrinho</a>
 </div>
 [% END %]
 [% END %]

 [% IF Koha.Preference('virtualshelves') %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
 <i class="fa fa-list"></i> Adicionar à lista <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
 [% IF add_to_some_private_shelves.count %]
 <li class="dropdown-header">Minhas listas</li>
 [% SET number_of_private_shelves = 0 %]
 [% FOREACH s IN add_to_some_private_shelves %]
 [% IF shelfnumber != s.shelfnumber %]
 <li>
 <a href="#" class="addtolist" data-shelfnumber="[% s.shelfnumber | html %]">[% s.shelfname | html %]</a>
 </li>
 [% SET number_of_private_shelves = number_of_private_shelves + 1 %]
 [% IF number_of_private_shelves == 10 %][% LAST %][% END %]
 [% END %]
 [% END %]
 [% END %]
 [% IF add_to_some_public_shelves.count %]
 <li class="dropdown-header">Listas públicas</li>
 [% SET number_of_public_shelves = 0 %]
 [% FOREACH s IN add_to_some_public_shelves %]
 [% IF shelfnumber != s.shelfnumber %]
 <li>
 <a href="#" data-shelfnumber="[% s.shelfnumber | html %]" class="addtolist">[% s.shelfname | html %]</a>
 </li>
 [% SET number_of_public_shelves = number_of_public_shelves + 1 %]
 [% IF number_of_public_shelves == 10 %][% LAST %][% END %]
 [% END %]
 [% END %]
 [% END %]
 <li role="separator" class="divider"></li>
 [% IF ( add_to_some_private_shelves and add_to_some_private_shelves.count > 10 ) or ( add_to_some_public_shelves and add_to_some_public_shelves.count > 10 ) %]
 <li>
 <a href="#" class="addtolist morelists">Mais listas</a>
 </li>
 [% END %]
 <li>
 <a href="#" class="addtolist newlist">Nova lista</a>
 </li>
 </ul>
 </div>
 [% END # /IF virtualshelves %]

 <div class="btn-group"><a id="printbiblio" class="btn btn-default"><i class="fa fa-print"></i> Imprimir</a></div>

[% IF ( CAN_user_reserveforothers ) %]
 [% SET items = biblio.items %]
 [% IF Context.Scalar(Context.Scalar(items, "filter_by_for_hold"), "count") %]
 [% IF ( holdfor ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">
 <i class="fa fa-sticky-note-o"></i>
 Reservar <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber | uri %]">Reservar</a></li>
 <li><a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber | uri %]&amp;findborrower=[% holdfor_patron.cardnumber | uri %]">Reservar [% INCLUDE 'patron-title.inc' patron => holdfor_patron no_title => 1 %]</a></li>
 </ul>
 </div>
 [% ELSE %]
 <div class="btn-group"><a id="placehold" class="btn btn-default" href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber | html %]"><i class="fa fa-sticky-note-o"></i> Reservar</a></div>
 [% END %]
 [% END %]
[% END %]

[% IF Koha.Preference('ArticleRequests') %]
 <div class="btn-group"><a id="placehold" class="btn btn-default" href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% biblionumber | html %]"><i class="fa fa-file-text-o"></i> Pedido de artigo</a></div>
[% END %]

[% IF ( CAN_user_acquisition_order_manage ) %]
 [% IF ( searchtoorder_basketno && searchtoorder_vendorid ) %]
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% searchtoorder_vendorid | uri %]&amp;basketno=[% searchtoorder_basketno | uri %]&amp;biblionumber=[% biblionumber | uri %]"><i class="fa fa-shopping-basket"></i> Adicionar encomenda</a>
 </div>
 [% END %]
[% END %]

[% FOREACH p IN plugins %]
 [% p.intranet_catalog_biblio_enhancements_toolbar_button | $raw %]
[% END %]

</div>

 <!--Modal for Dublin Core-->
 <div class="modal" id="exportModal_" tabindex="-1" role="dialog" aria-labelledby="exportLabelexportModal_" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <button type="button" class="closebtn" data-dismiss="modal" aria-hidden="true">&times;</button>
 <h3 id="exportLabelexportModal_">A exportar para Dublin Core...</h3>
 </div>
 <form method="get" action="/cgi-bin/koha/catalogue/export.pl">
 <div class="modal-body">
 <fieldset>
 <input id="input-simple" type="radio" name="format" value="rdfdc">
 <label for="input-simple">DC-RDF simples</label>
 <br>
 <input id="input-oai" type="radio" name="format" value="oaidc" checked>
 <label for="input-oai">OAI-DC</label>
 <br>
 <input id="input-srw" type="radio" name="format" value="srwdc">
 <label for="input-srw">SRW-DC</label>
 <br>
 </fieldset>
 </div>
 <div class="modal-footer">
 <button type="submit" class="btn btn-default">Exportar</button>
 <button class="btn btn-link" data-dismiss="modal" aria-hidden="true">Anular</button>
 </div>
 <input type="hidden" name="op" value="export" />
 <input type="hidden" name="bib" value="[% biblionumber | html %]" />
 </form>
 </div>
 </div>
 </div>
