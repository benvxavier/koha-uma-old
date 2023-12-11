[%- BLOCK main_permissions -%]
 [% SWITCH name %]
 [%- CASE 'superlibrarian' -%]
 <span class="main_permission superlibrarian_permission">Acesso a todas as funções da biblioteca</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'circulate' -%]
 <span class="main_permission circulate_permission">Emprestar e devolver exemplares</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'catalogue' -%]
 <span class="main_permission catalogue_permission">Acesso dos técnicos, permitindo ver o catálogo no interface dos técnicos</span>
 <span class="permissioncode">([% name | html %])</span> <span class="required">Necessário para autenticação no interface dos técnicos.</span>
 [%- CASE 'parameters' -%]
 <span class="main_permission parameters_permission">Gerir configurações do sistema do Koha (painel de administração)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'borrowers' -%]
 <span class="main_permission borrowers_permission">Adicionar, modificar ou ver informações do leitor</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'permissions' -%]
 <span class="main_permission permissions_permission">Definir as permissões do leitor</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reserveforothers' -%]
 <span class="main_permission reserveforothers_permission">Reservar e modificar reservas para os leitores</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editcatalogue' -%]
 <span class="main_permission editcatalogue_permission">Editar catálogo (Modificar dados bibliográficos)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'updatecharges' -%]
 <span class="main_permission updatecharges_permission">Gerir multas e taxas dos leitores</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'acquisition' -%]
 <span class="main_permission acquisition_permission">Gestão das aquisições</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions' -%]
 <span class="main_permission suggestions_permission">Gestão de sugestões</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tools' -%]
 <span class="main_permission tools_permission">Usar todas as ferramentas (expanda para permissões granulares)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editauthorities' -%]
 <span class="main_permission editauthorities_permission">Modificar autoridades</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'serials' -%]
 <span class="main_permission serials_permission">Gerir assinaturas de periódicos</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reports' -%]
 <span class="main_permission reports_permission">Permitir acesso ao módulo de relatórios</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'staffaccess' -%]
 <span class="main_permission staffaccess_permission">Permitir que os membros do staff modifiquem as permissões, nomes de utilizador e palavras-passes a outros membros do staff.</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'coursereserves' -%]
 <span class="main_permission coursereserves_permission">Reservas de curso</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'plugins' -%]
 <span class="main_permission plugins_permission">Plugins Koha</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'lists' -%]
 <span class="main_permission lists_permission">Listas</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'clubs' -%]
 <span class="main_permission clubs_permission">Grupos de leitores</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'ill' -%]
 <span class="main_permission ill_permission">Criar e modificar empréstimos inter-bibliotecas</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_check' -%]
 <span class="main_permission self_check_permission">Módulos automáticos</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stockrotation' -%]
 <span class="main_permission self_check_permission">Gerir as operações da rotação de stocks</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cash_management' -%]
 <span class="main_permission cash_management_permission">Gestão do dinheiro</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'problem_reports' -%]
 <span class="main_permission problem_reports_permission">Gestão dos relatórios de problemas do OPAC</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'recalls' -%]
 <span class="main_permission recalls_permission">Reclamações</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'erm' -%]
 <span class="main_permission erm_permission">Gerir o módulo de recursos electrónicos</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'loggedinlibrary' -%]
 <span class="main_permission loggedinlibrary_permission">Permitir ao técnico alterar a biblioteca onde está ligado</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]

[%- BLOCK sub_permissions -%]
 [% SWITCH name %]
 [%- CASE 'circulate_remaining_permissions' -%]
 <span class="sub_permission circulate_remaining_permissions_subpermission">
 Restantes permissões de circulação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'force_checkout' -%]
 <span class="sub_permission force_checkout_subpermission">
 Forçar empréstimo quando existe uma limitação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_restrictions' -%]
 <span class="sub_permission manage_restrictions_subpermission">
 Gerir as restrições de contas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'overdues_report' -%]
 <span class="sub_permission overdues_report_subpermission">
 Executar o relatório de atrasos de empréstimos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'override_renewals' -%]
 <span class="sub_permission override_renewals_subpermission">
 Sobrepor as renovações bloqueadas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_checkout_notes' %]
 <span class="sub_permission manage_checkout_notes_subpermission">
 Marcar as notas de empréstimo como vistas/não vistas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_accounts' -%]
 <span class="sub_permission manage_accounts_subpermission">
 Gerir tipos de débito e crédito das contas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 Gerir as regras de circulação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules_from_any_libraries' -%]
 <span class="sub_permission manage_circ_rules_from_any_libraries_subpermission">
 Editar as regras de circulação de qualquer biblioteca. Se não estiver definido, o utilizador autenticado apenas pode editar as regras de circulação da sua biblioteca (a permissão manage_circ_rules continua a ser necessária) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'parameters_remaining_permissions' -%]
 <span class="sub_permission parameters_remaining_permissions_subpermission">
 Restantes permissões de configuração do sistema </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 Gerir as regras de circulação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sysprefs' -%]
 <span class="sub_permission manage_sysprefs_subpermission">
 Gerir as preferências do sistema </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_libraries' -%]
 <span class="sub_permission manage_libraries_subpermission">
 Gerir as bibliotecas e os grupos hierárquicos de bibliotecas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_itemtypes' -%]
 <span class="sub_permission manage_itemtypes_subpermission">
 Gerir os tipos de documento </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_auth_values' -%]
 <span class="sub_permission manage_auth_values_subpermission">
 Gerir as categorias e respectivos valores autorizados </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_categories' -%]
 <span class="sub_permission manage_patron_categories_subpermission">
 Gerir as categorias de leitor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_restrictions' -%]
 <span class="sub_permission manage_patron_restrictions_subpermission">
 Gerir as restrições do leitor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_attributes' -%]
 <span class="sub_permission manage_patron_attributes_subpermission">
 Gerir os atributos de leitor adicionais </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_transfers' -%]
 <span class="sub_permission manage_transfers_subpermission">
 Gerir os limites de transferência entre bibliotecas e a matriz de custo de transporte </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_circ_alerts' -%]
 <span class="sub_permission manage_item_circ_alerts_subpermission">
 Gerir os alertas de circulação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_cities' -%]
 <span class="sub_permission manage_cities_subpermission">
 Gerir as cidades </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_frameworks' -%]
 <span class="sub_permission manage_marc_frameworks_subpermission">
 Gerir os modelos MARC de registos bibliográficos e de autoridades e testar os modelos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_classifications' -%]
 <span class="sub_permission manage_classifications_subpermission">
 Gerir as fontes de classificação e as regras de preenchimento </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_matching_rules' -%]
 <span class="sub_permission manage_matching_rules_subpermission">
 Gerir as regras de concordância de registos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_oai_sets' -%]
 <span class="sub_permission manage_oai_sets_subpermission">
 Gerir conjuntos OAI </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_search_fields' -%]
 <span class="sub_permission manage_item_search_fields_subpermission">
 Gerir os campos de pesquisa de exemplar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_filters' -%]
 <span class="sub_permission manage_search_filters_subpermission">
 Gerir as pesquisas guardadas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_engine_config' -%]
 <span class="sub_permission manage_search_engine_config_subpermission">
 Gerir a configuração do motor de pesquisa </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_overlay_rules' -%]
 <span class="sub_permission manage_marc_overlay_rules_subpermission">
 Gerir a configuração das regras MARC de sobreposição </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_targets' -%]
 <span class="sub_permission manage_search_targets_subpermission">
 Gerir a configuração de servidores Z39.50 e SRU </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_didyoumean' -%]
 <span class="sub_permission manage_didyoumean_subpermission">
 Gerir a configuração da funcionalidade Quis dizer? </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_smtp_servers' -%]
 <span class="sub_permission manage_manage_smtp_servers_subpermission">
 Gerir os servidores STMP </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_column_config' -%]
 <span class="sub_permission manage_column_config_subpermission">
 Gerir a configuração das colunas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_audio_alerts' -%]
 <span class="sub_permission manage_audio_alerts_subpermission">
 Gerir os alertas de áudio </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_additional_fields' -%]
 <span class="sub_permission manage_aditional_fields_subpermission">
 Gerir os campos adicionais para os cestos ou para as assinaturas (necessita das permissões edit_subscription ou order_manage) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sms_providers' -%]
 <span class="sub_permission manage_sms_providers_subpermission">
 Gerir os operadores de serviços móveis </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_usage_stats' -%]
 <span class="sub_permission manage_usage_stats_subpermission">
 Gerir as configurações das estatísticas de uso </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_mana' -%]
 <span class="sub_permission manage_mana_subpermission">
 Gerir a partilha de conteúdo com o Mana KB </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_keyboard_shortcuts' -%]
 <span class="sub_permission manage_keyboard_shortcuts_subpermission">
 Gerir os atalhos de teclado para o editor avançado de catalogação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_background_jobs' -%]
 <span class="sub_permission manage_background_jobs_subpermission">
 Gerir as tarefas em background </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_curbside_pickups' -%]
 <span class="sub_permission manage_curbside_pickups_subpermission">
 Gerir levantamentos de rua </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_borrowers' -%]
 <span class="sub_permission delete_borrowers_subpermission">
 Eliminar leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_borrowers' -%]
 <span class="sub_permission edit_borrowers_subpermission">
 Adicionar, modificar ou ver informações do leitor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_borrower_infos_from_any_libraries' -%]
 <span class="sub_permission view_borrower_infos_from_any_libraries_subpermission">
 Ver as informações de leitores de qualquer biblioteca. Se não estiver definido o utilizador autenticado pode aceder às informações dos leitores da sua biblioteca ou grupo de bibliotecas. </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'modify_holds_priority' -%]
 <span class="sub_permission modify_holds_priority_subpermission">
 Modificar prioridade de reserva </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'place_holds' -%]
 <span class="sub_permission place_holds_subpermission">
 Efetuar reservas para os leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_all_items' -%]
 <span class="sub_permission delete_all_items_subpermission">
 Eliminar todos os itens </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_catalogue' -%]
 <span class="sub_permission edit_catalogue_subpermission">
 Editar catálogo (Modificar dados bibliográficos) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'advanced_editor' -%]
 <span class="sub_permission advanced_editor_subpermission">
 Usar o editor de catalogação avançado (necessita a permissão edit_catalogue) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_shared_macros' -%]
 <span class="sub_permission create_shared_macros_subpermission">
 Criar macros partilhadas (necessita da permissão advanced_editor) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_shared_macros' -%]
 <span class="sub_permission delete_shared_macros_subpermission">
 Eliminar macros partilhadas (necessita da permissão advanced_editor) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items' -%]
 <span class="sub_permission edit_items_subpermission">
 Editar exemplares (não incluindo os exemplares restritos por grupo de biblioteca) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_any_item' -%]
 <span class="sub_permission edit_items_subpermission">
 Editar qualquer exemplar incluindo os exemplares que normalmente estão restritos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items_restricted' -%]
 <span class="sub_permission edit_items_restricted_subpermission">
 Limitar a modificação de exemplares aos subcampos definidos na preferência SubfieldsToAllowForRestrictedEditing (por favor note que a permissão edt_items é necessária) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'fast_cataloging' -%]
 <span class="sub_permission fast_cataloging_subpermission">
 Catalogação rápida </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_groups' -%]
 <span class="sub_permission manage_item_groups_subpermission">
 Criar, atualizar e eliminar grupos de exemplares, adicionar e eliminar exemplares de um grupo </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_editor_templates' -%]
 <span class="sub_permission manage_item_editor_templates_subpermission">
 Criar, atualizar e eliminar modelos de edição de exemplares pertencentes a terceiros </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'remaining_permissions' -%]
 <span class="sub_permission remaining_permissions_subpermission">
 Restantes permissões para a gestão de multas e taxas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'discount' -%]
 <span class="sub_permission discount_subpermission">
 Descontar débitos aos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'payout' -%]
 <span class="sub_permission payout_subpermission">
 Pagar créditos aos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'refund' -%]
 <span class="sub_permission refund_subpermission">
 Reembolsar pagamento aos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'writeoff' -%]
 <span class="sub_permission writeoff_subpermission">
 Amortizar multas e taxas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_invoice' -%]
 <span class="sub_permission manual_invoice_subpermission">
 Adicionar débitos manuais à conta do leitor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_credit' -%]
 <span class="sub_permission manual_credit_subpermission">
 Adicionar créditos manuais à conta do leitor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_manage' -%]
 <span class="sub_permission suggestions_manage_subpermission">
 Gerir as sugestões de aquisição </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_add_del' -%]
 <span class="sub_permission budget_add_del_subpermission">
 Adicionar e eliminar fundos (mas não pode modificar fundos) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage' -%]
 <span class="sub_permission budget_manage_subpermission">
 Gerir os fundos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage_all' -%]
 <span class="sub_permission budget_manage_all_subpermission">
 Gerir todos os fundos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_modify' -%]
 <span class="sub_permission budget_modify_subpermission">
 Modificar fundos (não pode criar entradas, mas pode modificar as existentes) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'contracts_manage' -%]
 <span class="sub_permission contracts_manage_subpermission">
 Gerir os contratos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'group_manage' -%]
 <span class="sub_permission group_manage_subpermission">
 Gerir grupos de cestos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage' -%]
 <span class="sub_permission order_manage_subpermission">
 Gerir cestos e encomendas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage_all' -%]
 <span class="sub_permission order_manage_all_subpermission">
 Gerir todos os cestos e encomendas, independentemente das restrições de cada </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_receive' -%]
 <span class="sub_permission order_receive_subpermission">
 Receber encomendas e gerir remessas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'period_manage' -%]
 <span class="sub_permission period_manage_subpermission">
 Gerir os orçamentos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'planning_manage' -%]
 <span class="sub_permission planning_manage_subpermission">
 Gerir os planeamentos de orçamentos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'vendors_manage' -%]
 <span class="sub_permission vendors_manage_subpermission">
 Gerir os fornecedores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'currencies_manage' -%]
 <span class="sub_permission currencies_manage_subpermission">
 Gerir as moedas e as taxas de câmbio </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_upload_patron_images' -%]
 <span class="sub_permission batch_upload_patron_images_subpermission">
 Carregar fotografias dos leitores em lote ou uma de cada vez </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_anonymize_patrons' -%]
 <span class="sub_permission delete_anonymize_patrons_subpermission">
 Eliminar leitores antigos e anonimizar histórico de circulação (elimina histórico de empréstimo do leitor) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_extend_due_dates' -%]
 <span class="sub_permission batch_extend_due_dates_subpermission">
 Prolongar datas de devolução em lote </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_calendar' -%]
 <span class="sub_permission edit_calendar_subpermission">
 Definir os dias de encerramento da biblioteca </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_additional_contents' -%]
 <span class="sub_permission edit_additional_contents_subpermission">
 Redação de conteúdos para o OPAC e para o interface dos técnicos (notícias e HTML personalizado) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notice_status_triggers' -%]
 <span class="sub_permission edit_notice_status_triggers_subpermission">
 Definir as regras e datas de envio das notificações </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notices' -%]
 <span class="sub_permission edit_notices_subpermission">
 Definir avisos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_patrons' -%]
 <span class="sub_permission edit_patrons_subpermission">
 Modificar leitores em lote </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_quotes' -%]
 <span class="sub_permission edit_quotes_subpermission">
 Editar frases para a funcionalidade frase do dia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'export_catalog' -%]
 <span class="sub_permission export_catalog_subpermission">
 Exportar registos bibliográficos e exemplares </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'import_patrons' -%]
 <span class="sub_permission import_patrons_subpermission">
 Importar dados dos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'inventory' -%]
 <span class="sub_permission inventory_subpermission">
 Inventariar (balanço) o catálogo </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchdel' -%]
 <span class="sub_permission items_batchdel_subpermission">
 Eliminar exemplares em lote </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod' -%]
 <span class="sub_permission items_batchmod_subpermission">
 Modificar exemplares em lote </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod_restricted' -%]
 <span class="sub_permission items_batchmod_restricted_subpermission">
 Limitar a modificação de exemplares em lote aos subcampos definidos na preferência SubfieldsToAllowForRestrictedBatchmod (por favor note que a permissão items_batchmod é necessária) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'label_creator' -%]
 <span class="sub_permission label_creator_subpermission">
 Criar etiquetas e código de barras a partir do catálogo e dos dados do leitor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_csv_profiles' -%]
 <span class="sub_permission manage_csv_profiles_subpermission">
 Gerir os perfis de exportação para CSV </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_lists' -%]
 <span class="sub_permission manage_patron_lists_subpermission">
 Adicionar, editar ou eliminar listas de leitores e os seus conteúdos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_staged_marc' -%]
 <span class="sub_permission manage_staged_marc_subpermission">
 Gestão dos registos MARC processados, incluindo a conclusão ou reversão da importação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'marc_modification_templates' -%]
 <span class="sub_permission marc_modification_templates_subpermission">
 Gerir os modelos de modificação MARC </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_comments' -%]
 <span class="sub_permission moderate_comments_subpermission">
 Moderar os comentários dos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_tags' -%]
 <span class="sub_permission moderate_tags_subpermission">
 Moderar as etiquetas dos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchdel' -%]
 <span class="sub_permission records_batchdel_subpermission">
 Eliminar registos em lote (bibliográficos ou de autoridade) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchmod' -%]
 <span class="sub_permission records_batchmod_subpermission">
 Modificar registos em lote (bibliográficos ou de autoridade) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'rotating_collections' -%]
 <span class="sub_permission rotating_collections_subpermission">
 Gerir as coleções </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'schedule_tasks' -%]
 <span class="sub_permission schedule_tasks_subpermission">
 Calendarização de tarefas a executar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stage_marc_import' -%]
 <span class="sub_permission stage_marc_import_subpermission">
 Transferência de registos MARC para o depósito </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_local_cover_images' -%]
 <span class="sub_permission upload_local_cover_images_subpermission">
 Carregar imagens locais de capa </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_system_logs' -%]
 <span class="sub_permission view_system_logs_subpermission">
 Consultar os registos do sistema </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'check_expiration' -%]
 <span class="sub_permission check_expiration_subpermission">
 Verificar a data de expiração de um periódico </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'claim_serials' -%]
 <span class="sub_permission claim_serials_subpermission">
 Reclamar números em falta </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_subscription' -%]
 <span class="sub_permission create_subscription_subpermission">
 Criar uma nova assinatura </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_subscription' -%]
 <span class="sub_permission delete_subscription_subpermission">
 Eliminar uma assinatura </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_subscription' -%]
 <span class="sub_permission edit_subscription_subpermission">
 Modificar assinatura existente </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'receive_serials' -%]
 <span class="sub_permission receive_serials_subpermission">
 Receção de periódicos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'renew_subscription' -%]
 <span class="sub_permission renew_subscription_subpermission">
 Renovar a assinatura </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'routing' -%]
 <span class="sub_permission routing_subpermission">
 Circulação </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'superserials' -%]
 <span class="sub_permission superserials_subpermission">
 Gerir as assinaturas de qualquer biblioteca (apenas aplicável se a preferência IndependentBranches estiver em uso) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reports' -%]
 <span class="sub_permission delete_reports_subpermission">
 Eliminar relatórios SQL </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_reports' -%]
 <span class="sub_permission create_reports_subpermission">
 Criar relatórios SQL </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'execute_reports' -%]
 <span class="sub_permission execute_reports_subpermission">
 Executar relatórios SQL </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'add_reserves' -%]
 <span class="sub_permission add_reserves_subpermission">
 Adicionar reservas de curso </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reserves' -%]
 <span class="sub_permission delete_reserves_subpermission">
 Remover reservas de curso </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_courses' -%]
 <span class="sub_permission manage_courses_subpermission">
 Adicionar, editar ou eliminar cursos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'configure' -%]
 <span class="sub_permission configure_subpermission">
 Configurar plugins </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage' -%]
 <span class="sub_permission manage_subpermission">
 Gerir os plugins ( instalar / remover ) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'report' -%]
 <span class="sub_permission report_subpermission">
 Usar plugins de relatórios </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tool' -%]
 <span class="sub_permission tool_subpermission">
 Usar plugins de ferramenta </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_public_lists' -%]
 <span class="sub_permission delete_public_lists_subpermission">
 Eliminar listas públicas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_lists' -%]
 <span class="sub_permission edit_public_lists_subpermission">
 Editar listas públicas (Nome, definições e permissões mas não os conteúdos) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_list_contents' -%]
 <span class="sub_permission edit_public_list_contents_subpermission">
 Editar conteúdos das listas públicas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_general_files' -%]
 <span class="sub_permission upload_general_files_subpermission">
 Carregar qualquer ficheiro </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_manage' -%]
 <span class="sub_permission upload_manage_subpermission">
 Gerir ficheiros carregados (<em>Inútil sem upload_general_files</em>)
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'access_files' -%]
 <span class="sub_permission access_files_subpermission">
 Aceder a ficheiros guardados no servidor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_clubs' -%]
 <span class="sub_permission edit_clubs_subpermission">
 Criar e editar grupos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_templates' -%]
 <span class="sub_permission edit_templates_subpermission">
 Criar e editar modelos de grupo </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'enroll' -%]
 <span class="sub_permission enroll_subpermission">
 Inscrever leitores nos grupos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edi_manage' -%]
 <span class="sub_permission edi_manage_subpermission">
 Gerir transmissões EDIFACT </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reopen_closed_invoices' -%]
 <span class="sub_permission reopen_closed_invoices_subpermission">
 Reabrir faturas fechadas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_invoices' -%]
 <span class="sub_permission edit_invoices_subpermission">
 Editar avisos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_invoices' -%]
 <span class="sub_permission delete_invoices_subpermission">
 Eliminar aviso </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'merge_invoices' -%]
 <span class="sub_permission merge_invoices_subpermission">
 Unificar faturas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_baskets' -%]
 <span class="sub_permission delete_baskets_subpermission">
 Eliminar cestos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# self_check %]
 [%- CASE 'self_checkin_module' -%]
 <span class="sub_permission self_checkin_module_subpermission">
 Entrar no sistema de auto devolução. Nota: esta permissão evita que o leitor consiga usar qualquer outra funcionalidade do OPAC </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_checkout_module' -%]
 <span class="sub_permission self_checkout_module_subpermission">
 Executar auto-empréstimos no OPAC. Deve ser usado para o leitor que corresponda à preferência AutoSelfCheckID </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rota_items' -%]
 <span class="sub_permission manage_rota_items_subpermission">
 Adicionar ou remover exemplares das rotas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rotas' -%]
 <span class="sub_permission manage_rotas_subpermission">
 Criar, editar ou eliminar rotas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# cash_management %]
 [%- CASE 'manage_cash_registers' -%]
 <span class="sub_permission manage_cash_registers_subpermission">
 Adicionar, editar ou arquivar caixas registadoras </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'takepayment' -%]
 <span class="sub_permission takepayment_subpermission">
 Aceder ao ponto de venda e aceitar pagamentos </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cashup' -%]
 <span class="sub_permission cashup_subpermission">
 Realizar ações de levantamento nas caixas registadoras </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'anonymous_refund' -%]
 <span class="sub_permission anonymous_refund_subpermission">
 Realizar ações de reembolso anônimas </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# problem_reports %]
 [%- CASE 'manage_problem_reports' -%]
 <span class="sub_permission manage_problem_reports_subpermission">
 Gerir os relatórios de problemas do OPAC </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# recalls %]
 [%- CASE 'manage_recalls' -%]
 <span class="sub_permission place_recalls_subpermission">
 Gerir reclamações dos leitores </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# identity_providers %]
 [%- CASE 'manage_identity_providers' -%]
 <span class="sub_permission manage_identity_providers_subpermission">
 Gerir fornecedores de identidade </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]
