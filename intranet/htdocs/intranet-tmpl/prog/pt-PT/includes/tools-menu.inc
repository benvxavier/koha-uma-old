[% USE Koha %]
[% USE Branches %]
[% USE Registers %]

<div id="navmenu">
 <div id="navmenulist">
 <ul>
 <li><a href="/cgi-bin/koha/tools/tools-home.pl">Ferramentas</a></li>
 </ul>
 [% IF ( CAN_user_tools_manage_patron_lists || CAN_user_clubs || CAN_user_tools_moderate_comments || CAN_user_tools_import_patrons  || CAN_user_tools_edit_notices || CAN_user_tools_edit_notice_status_triggers || CAN_user_tools_label_creator || CAN_user_tools_delete_anonymize_patrons  || CAN_user_tools_edit_patrons || CAN_user_tools_moderate_tags || ( CAN_user_tools_batch_upload_patron_images && Koha.Preference('patronimages') ) || CAN_user_tools_rotating_collections ) %]
 <h5>Leitores e empréstimo</h5>
 <ul>
 [% IF ( CAN_user_tools_manage_patron_lists ) %]
 <li><a href="/cgi-bin/koha/patron_lists/lists.pl">Listas de leitores</a></li>
 [% END %]
 [% IF (CAN_user_clubs) %]
 <li><a href="/cgi-bin/koha/clubs/clubs.pl">Grupos de leitores</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_comments ) %]
 <li><a href="/cgi-bin/koha/reviews/reviewswaiting.pl">Comentários</a></li>
 [% END %]
 [% IF ( CAN_user_tools_import_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/import_borrowers.pl">Importar leitores</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notices ) %]
 <li><a href="/cgi-bin/koha/tools/letter.pl">Avisos e recibos</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notice_status_triggers ) %]
 <li><a href="/cgi-bin/koha/tools/overduerules.pl">Agendar avisos de atrasos</a></li>
 [% END %]
 [% IF ( CAN_user_tools_label_creator ) %]
 <li><a href="/cgi-bin/koha/patroncards/home.pl">Cartões de leitor</a></li>
 [% END %]
 [% IF ( CAN_user_tools_delete_anonymize_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/cleanborrowers.pl">Eliminar e anonimizar leitores em lote</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/modborrowers.pl">Modificar leitores em lote</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_extend_due_dates ) %]
 <li><a href="/cgi-bin/koha/tools/batch_extend_due_dates.pl">Prolongar datas de devolução em lote</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_tags ) %]
 <li><a href="/cgi-bin/koha/tags/review.pl">Etiquetas</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_upload_patron_images && Koha.Preference('patronimages') ) %]
 <li><a href="/cgi-bin/koha/tools/picture-upload.pl">Carregar fotografias dos leitores</a></li>
 [% END %]
 [% IF ( CAN_user_tools_rotating_collections ) %]
 <li><a href="/cgi-bin/koha/rotating_collections/rotatingCollections.pl">Coleções</a></li>
 [% END %]
 </ul>
 [% END # /IF ( CAN_user_tools_items_batchdel... %]

 [% IF ( CAN_user_tools_edit_calendar || CAN_user_tools_manage_csv_profiles || CAN_user_tools_view_system_logs || CAN_user_tools_edit_additional_contents  || CAN_user_tools_schedule_tasks || CAN_user_tools_edit_quotes || ( Koha.ArePluginsEnabled() && CAN_user_plugins_tool )  || CAN_user_tools_upload_general_files || CAN_user_tools_access_files ) %]
 <h5>Ferramentas adicionais</h5>
 <ul>
 [% IF ( CAN_user_tools_edit_calendar ) %]
 <li><a href="/cgi-bin/koha/tools/holidays.pl">Calendário</a></li>
 [% END %]
 [% IF ( CAN_user_tools_manage_csv_profiles ) %]
 <li><a href="/cgi-bin/koha/tools/csv-profiles.pl">Perfis CSV</a></li>
 [% END %]
 [% IF ( CAN_user_tools_view_system_logs ) %]
 <li><a href="/cgi-bin/koha/tools/viewlog.pl">Visualização dos logs</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_additional_contents ) %]
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=news">Notícias</a></li>
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=html_customizations">HTML personalizados</a></li>
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=pages">Páginas</a></li>
 [% END %]
 [% IF ( CAN_user_tools_schedule_tasks ) %]
 <li><a href="/cgi-bin/koha/tools/scheduler.pl">Calendarização de tarefas</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_quotes ) %]
 <li><a href="/cgi-bin/koha/tools/quotes.pl">Editor de frase</a></li>
 [% END %]
 [% IF ( plugins_enabled && CAN_user_plugins_tool ) %]
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=tool">Plugins de ferramentas</a></li>
 [% END %]
 [% IF ( CAN_user_tools_upload_general_files ) %]
 <li><a href="/cgi-bin/koha/tools/upload.pl">Carregamentos</a></li>
 [% END %]
 [% IF ( CAN_user_tools_access_files ) %]
 <li><a href="/cgi-bin/koha/tools/access_files.pl">Aceder a ficheiros</a></li>
 [% END %]
 [% IF ( Koha.Preference('OPACReportProblem') && CAN_user_problem_reports ) %]
 <li><a href="/cgi-bin/koha/tools/problem-reports.pl">Relatórios de problemas do OPAC</a></li>
 [% END %]
 </ul>
 [% END # /IF ( CAN_user_tools_edit_calendar... %]
 [% IF ( Koha.Preference('UseCashRegisters') && ( CAN_user_cash_management_cashup || CAN_user_cash_management_anonymous_refund ) ) %]
 <h5>Gestão do dinheiro</h5>
 <ul>
 <li><a href="/cgi-bin/koha/pos/registers.pl">Resumo de contabilidade de [% Branches.GetLoggedInBranchname | html %]</a></li>
 <li><a href="/cgi-bin/koha/pos/register.pl">Histórico de transações para [% Registers.session_register_name | html %]</a></li>
 </ul>
 [% END %]
 </div> <!-- /#navmenulist -->
</div> <!-- /#navmenu -->
