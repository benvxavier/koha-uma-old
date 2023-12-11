[% USE Koha %]

<div id="navmenu">
<div id="navmenulist">

 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <h5>Preferências do sistema</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/preferences.pl">Preferências do sistema</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_libraries || CAN_user_parameters_manage_itemtypes || CAN_user_parameters_manage_auth_values ) %]
 <h5>Parâmetros de base</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/branches.pl">Bibliotecas</a></li>
 <li><a href="/cgi-bin/koha/admin/library_groups.pl">Grupos de bibliotecas</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_itemtypes ) %]
 <li><a href="/cgi-bin/koha/admin/itemtypes.pl">Tipos de documento</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_auth_values ) %]
 <li><a href="/cgi-bin/koha/admin/authorised_values.pl">Valores Autorizados</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_patron_categories || CAN_user_parameters_manage_circ_rules || CAN_user_parameters_manage_patron_attributes || CAN_user_parameters_manage_transfers || CAN_user_parameters_manage_item_circ_alerts || CAN_user_parameters_manage_cities || CAN_user_parameters_manage_curbside_pickups || CAN_user_parameters_manage_patron_restrictions ) %]
 <h5>Leitores e empréstimo</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_patron_categories ) %]
 <li><a href="/cgi-bin/koha/admin/categories.pl">Categorias de Leitores</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_circ_rules ) %]
 <li><a href="/cgi-bin/koha/admin/smart-rules.pl">Regras de empréstimo e multas</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_attributes ) %]
 <li><a href="/cgi-bin/koha/admin/patron-attr-types.pl">Tipos de atributos de leitor</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_transfers ) %]
 <li><a href="/cgi-bin/koha/admin/branch_transfer_limits.pl">Limites da biblioteca</a></li>
 <li><a href="/cgi-bin/koha/admin/transport-cost-matrix.pl">Tabela de custos de transporte</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_circ_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/item_circulation_alerts.pl">Avisos de empréstimo</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCirculationDesks') && CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/desks.pl">Balcões</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cities ) %]
 <li><a href="/cgi-bin/koha/admin/cities.pl">Cidades</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_curbside_pickups ) %]
 <li><a href="/cgi-bin/koha/admin/curbside_pickup.pl">Levantamento de rua</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_restrictions ) %]
 <li><a href="/cgi-bin/koha/admin/restrictions.pl">Tipos de restrições do leitor</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts || ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) ) %]
 <h5>Contabilidade</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">Tipos de débito</a></li>
 <li><a href="/cgi-bin/koha/admin/credit_types.pl">Tipos de crédito</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">Caixas registadoras</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF CAN_user_plugins && plugins_enabled %]
 <h5>Plugins</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl">Plugins</a></li>
 </ul>
 [% END %]

 [% IF CAN_user_parameters_manage_background_jobs %]
 <h5>Tarefas</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/background_jobs.pl">Tarefas</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_marc_frameworks || CAN_user_parameters_manage_classifications || CAN_user_parameters_manage_matching_rules || CAN_user_parameters_manage_oai_sets || CAN_user_parameters_manage_item_search_fields || CAN_user_parameters_manage_search_engine_config || CAN_user_parameters_manage_marc_overlay_rules || ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) ) %]
 <h5>Catálogo</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/biblio_framework.pl">Modelo bibliográfico MARC</a></li>
 <li><a href="/cgi-bin/koha/admin/koha2marclinks.pl">Ligações Koha => MARC</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/checkmarc.pl">Teste do modelo bibliográfico MARC</a></li>
 <li><a href="/cgi-bin/koha/admin/authtypes.pl">Tipos de autoridade</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_classifications ) %]
 <li><a href="/cgi-bin/koha/admin/classsources.pl">Configuração da classificação</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_matching_rules ) %]
 <li><a href="/cgi-bin/koha/admin/matching-rules.pl">Regras de concordância</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_overlay_rules ) %]
 <li><a href="/cgi-bin/koha/admin/marc-overlay-rules.pl">Regras de sobreposição de registos</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_oai_sets ) %]
 <li><a href="/cgi-bin/koha/admin/oai_sets.pl">Configuração dos conjuntos OAI</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_search_fields ) %]
 <li><a href="/cgi-bin/koha/admin/items_search_fields.pl">Campos de pesquisa de exemplar</a></li>
 [% END %]
 [% IF ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) %]
 <li><a href="/cgi-bin/koha/admin/search_filters.pl">Filtros de pequisa</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_engine_config ) %]
 <li><a href="/cgi-bin/koha/admin/searchengine/elasticsearch/mappings.pl">Configuração do motor de pesquisa (Elasticsearch)</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_acquisition_currencies_manage || CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) ) %]
 <h5>Parâmetros das aquisições</h5>
 <ul>
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Moedas e câmbios</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Orçamentos</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Fundos</a></li>
 [% END %]
 [% IF ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">Contas EDI</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">EANs</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_identity_providers || CAN_user_parameters_manage_smtp_servers || CAN_user_parameters_manage_search_targets || CAN_user_parameters_manage_didyoumean || CAN_user_parameters_manage_column_config || CAN_user_parameters_manage_audio_alerts || ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) || CAN_user_parameters_manage_usage_stats || CAN_user_parameters_manage_additional_fields || ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) ) %]
 <h5>Parâmetros adicionais</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_identity_providers) %]
 <li><a href="/cgi-bin/koha/admin/identity_providers.pl">Fornecedores de identidade</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_targets ) %]
 <li><a href="/cgi-bin/koha/admin/z3950servers.pl">Servidores Z39.50/SRU</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_smtp_servers ) %]
 <li><a href="/cgi-bin/koha/admin/smtp_servers.pl">Servidores SMTP</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_didyoumean ) %]
 <li><a href="/cgi-bin/koha/admin/didyoumean.pl">Quis dizer?</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_column_config ) %]
 <li><a href="/cgi-bin/koha/admin/columns_settings.pl">Configurações da tabela</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_audio_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/audio_alerts.pl">Alertas de áudio</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) %]
 <li><a href="/cgi-bin/koha/admin/sms_providers.pl">Operadores de serviços móveis</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_usage_stats ) %]
 <li><a href="/cgi-bin/koha/admin/usage_statistics.pl">Partilhar as estatísticas de uso</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_mana ) %]
 <li><a href="/cgi-bin/koha/admin/share_content.pl">Partilhar conteúdo com o Mana KB</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_additional_fields ) %]
 <li><a href="/cgi-bin/koha/admin/additional-fields.pl">Campos adicionais</a></li>
 [% END %]
 [% IF ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) %]
 <li><a href="/cgi-bin/koha/admin/adveditorshortcuts.pl">Atalhos de teclado</a></li>
 [% END %]
 </ul>
 [% END %]
</div>
</div>
