[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">

 [% IF ( CAN_user_tools_stage_marc_import || CAN_user_tools_manage_staged_marc ) %]
 <h5>Importar</h5>
 <ul>
 [% IF ( CAN_user_tools_stage_marc_import ) %]
 <li>
 <a href="/cgi-bin/koha/tools/stage-marc-import.pl">Importação de registos bibliográficos</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_manage_staged_marc ) %]
 <li>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl">Gestão dos registos processados</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_export_catalog ) %]
 <h5>Exportar</h5>
 <ul>
 [% IF ( CAN_user_tools_export_catalog ) %]
 <li>
 <a href="/cgi-bin/koha/tools/export.pl">Exportar dados do catálogo</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_inventory || ( ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue ) ) %]
 <h5>Relatórios</h5>
 <ul>
 [% IF ( CAN_user_tools_inventory ) %]
 <li>
 <a href="/cgi-bin/koha/tools/inventory.pl">Inventário</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/concerns.pl">Problemas de catalogação</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod || CAN_user_tools_items_batchdel || CAN_user_tools_records_batchmod || CAN_user_tools_records_batchdel || CAN_user_tools_marc_modification_templates ) %]
 <h5>Edição em lote</h5>
 <ul>
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li>
 <a href="/cgi-bin/koha/tools/batchMod.pl">Modificar exemplares em lote</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_items_batchdel ) %]
 <li>
 <a href="/cgi-bin/koha/tools/batchMod.pl?del=1">Eliminar exemplares em lote</a>
 </li>
 [% END %]
 [% IF CAN_user_tools_records_batchmod %]
 <li>
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl">Modificar registos em lote</a>
 </li>
 [% END %]
 [% IF CAN_user_tools_records_batchdel %]
 <li>
 <a href="/cgi-bin/koha/tools/batch_delete_records.pl">Eliminar registos em lote</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_marc_modification_templates ) %]
 <li>
 <a href="/cgi-bin/koha/tools/marc_modification_templates.pl">Modelos de modificação MARC</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod || ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) ) %]
 <h5>Automático</h5>
 <ul>
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li>
 <a href="/cgi-bin/koha/tools/automatic_item_modification_by_age.pl">Modificação de exemplares por idade</a>
 </li>
 [% END %]
 [% IF ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) %]
 <li>
 <a href="/cgi-bin/koha/tools/stockrotation.pl">Rotação de stock</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_label_creator || CAN_user_tools_upload_local_cover_images ) %]
 <h5>Ferramentas</h5>
 <ul>
 [% IF ( CAN_user_tools_label_creator ) %]
 <li>
 <a href="/cgi-bin/koha/labels/label-home.pl">Etiquetas</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/labels/barcode-print.pl">Gerador de imagem de código de barras</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/labels/spinelabel-home.pl">Criar Etiqueta Rápida</a>
 </li>
 [% END %]

 [% IF ( CAN_user_tools_upload_local_cover_images ) %]
 <li>
 <a href="/cgi-bin/koha/tools/upload-cover-image.pl">Carregar imagens locais de capa</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters ) %]
 <h5>Administração</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <li>
 <a class="circ-button" href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing">Preferências</a>
 </li>
 [% END %]
 <li>
 <a class="circ-button" href="/cgi-bin/koha/admin/admin-home.pl">Configuração</a>
 </li>
 </ul>
 [% END %]

 </div>
</div>
