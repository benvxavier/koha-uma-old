[% INCLUDE 'blocking_errors.inc' %]
[% USE Koha %]
[% USE Branches %]
[% USE Categories %]
[% USE AuthorisedValues %]
[% USE scalar %]
<div id="toolbar" class="btn-toolbar">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="editpatron" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=modify&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa fa-pencil"></i> Alterar</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF patron.is_adult AND Koha.Preference("borrowerRelationship") %]
 <a id="addchild" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=add&amp;guarantor_id=[% patron.borrowernumber | html %]"><i class="fa fa-plus"></i> Adicionar assegurado</a>
 [% END %]
 <a id="changepassword" class="btn btn-default" href="/cgi-bin/koha/members/member-password.pl?member=[% patron.borrowernumber | html %]"><i class="fa fa-lock"></i> Modificar a palavra-passe</a>
 <a id="duplicate" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=duplicate&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa fa-copy"></i> Duplicado</a>
 [% END %]

 [% IF CAN_user_circulate_circulate_remaining_permissions %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-print"></i> Imprimir <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a id="printsummary" href="#">Imprimir sumário</a></li>
 <li><a id="printslip" href="#">Imprimir recibo</a></li>
 <li><a id="printquickslip" href="#">Imprimir recibo</a></li>
 [% IF patron.account_balance != 0 %]
 <li><a id="printfineslip" target="_blank" href="/cgi-bin/koha/members/printnotice.pl?notice=ACCOUNTS_SUMMARY&borrowernumber=[% patron.borrowernumber | uri %]">Imprimir saldo da conta</a></li>
 [% END %]
 [% IF patron.has_overdues %]
 <li><a id="print_overdues" href="#">Imprimir atrasos</a></li>
 [% END %]
 <li><a id="printcheckinslip" href="#">Imprimir talão de devolução</a></li>
 </ul>
 </div>
 [% END %]

 [% IF ( CAN_user_reserveforothers ) %]
 <a id="searchtohold" class="btn btn-default" href="#"><i class="fa fa-search"></i> Pesquisar para reservar</a>
 [% END %]

 <a id="addnewmessageLabel" href="#add_message_form" data-toggle="modal" class="btn btn-default"><i class="fa fa-comment-o"></i> Adicionar mensagem</a>

 [% IF Koha.Preference('CurbsidePickup') %]
 <a id="curbsidePickupLabel" href="/cgi-bin/koha/circ/curbside_pickups.pl?op=find-patron&borrowernumber=[% patron.borrowernumber | html %]" class="btn btn-default"><i class="fa fa-refresh"></i> Agendar levantamento</a>
 [% END %]

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">Mais <span class="caret"></span></button>
 <ul class="dropdown-menu dropdown-menu-right">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <li><a id="renewpatron" href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | html %]&amp;destination=[% destination | html %]&amp;reregistration=y">Renovar leitor</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="renewpatron" title="Não está autorizado a renovar leitores">Renovar leitor</a></li>
 [% END %]
 [% IF ( CAN_user_permissions ) %]
 <li><a id="patronflags" href="/cgi-bin/koha/members/member-flags.pl?member=[% patron.borrowernumber | html %]">Definir as permissões</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="patronflags" title="Não está autorizado a definir permissões">Definir as permissões</a></li>
 [% END %]

 [% IF ( Koha.Preference('TwoFactorAuthentication') == 'enforced' || Koha.Preference('TwoFactorAuthentication') == 'enabled' ) && logged_in_user.borrowernumber == patron.borrowernumber %]
 <li><a id="twofa" href="/cgi-bin/koha/members/two_factor_auth.pl">Gerir a autenticação dois fatores</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && useDischarge %]
 <li><a href="/cgi-bin/koha/members/discharge.pl?borrowernumber=[% patron.borrowernumber | uri %]">Quitação</a></li>
 [% END %]

 [% IF Koha.Preference('RESTOAuth2ClientCredentials') %]
 [% IF CAN_user_superlibrarian OR loggedinusernumber == patron.borrowernumber %]
 <li><a id="apikeys" href="/cgi-bin/koha/members/apikeys.pl?patron_id=[% patron.borrowernumber | html %]">Gerir chaves da API</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="apikeys" title="Não está autorizado a gerir as chaves da API">Gerir chaves da API</a></li>
 [% END %]
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <li><a id="sendwelcome" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_welcome">Enviar email de boas-vindas</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && patron.category.effective_reset_password %]
 <li><a id="resetpassword" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_password_reset">Enviar recuperação de palavra-passe</a></li>
 [% END %]

 [% IF CAN_user_borrowers_delete_borrowers %]
 <li><a id="deletepatron" href="#">Apagar</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deletepatron" title="Não está autorizado a eliminar leitores">Apagar</a></li>
 [% END %]
 [% SET adult_categories = Categories.scalar.all(category_type => 'A') %]
 [% IF adult_categories.count > 0 %]
 [% IF patron.is_child %]
 <li><a id="updatechild" href="#">Transformar criança em adulto</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="updatechild" title="Leitor é um adulto">Transformar criança em adulto</a></li>
 [% END %]
 [% END %]
 [% IF Koha.Preference('intranetreadinghistory') %]
 [%IF ( privacy == 2 ) %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="exportbarcodes" title="Não permitido pelas configurações de privacidade do leitor">Exportar os códigos de barras devolvidos hoje</a></li>
 [% ELSE %]
 <li><a id="exportcheckins" href="#">Exportar os códigos de barras devolvidos hoje</a></li>
 [% END %]
 [% END %]
 </ul>
 </div>
</div>

<!-- Modal -->
<div id="add_message_form" class="modal" tabindex="-1" role="dialog" aria-labelledby="addnewmessageLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="message_form" name="message_f">
 <div class="modal-header">
 <h3>Deixe uma mensagem</h3>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="message_type">Adicionar uma mensagem para:</label>
 <select name="message_type" id="message_type">
 <option value="L">Nota interna</option>
 <option value="B">OPAC - [% patron.firstname | html %] [% patron.surname | html %]</option>
 </select>
 </div>
 [% bor_notes = AuthorisedValues.Get( 'BOR_NOTES' ) %]
 [% IF bor_notes %]
 <div class="form-group">
 <label for="select_patron_messages">Notas pré-definidas: </label>
 <select name="type" id="select_patron_messages">
 <option value="">Seleccionar nota</option>
 [% FOREACH bor_note IN bor_notes %]
 <option value="[% bor_note.lib | html %]">[% bor_note.lib | html %]</option>
 [% END %]
 </select>
 </div>
 [% END %]
 <div class="form-group">
 <textarea rows="3" class="modal-textarea" name="borrower_message" id="borrower_message" ></textarea>
 </div>
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input type="hidden" name="batch" value="[% batch | html %]" />
 <input type="hidden" name="branchcode" value="[% Branches.GetLoggedInBranchcode | html %]" />
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> Guardar</button>
 <button class="btn btn-default deny cancel" href="#" data-dismiss="modal" aria-hidden="true"><i class="fa fa-times"></i> Anular</button>
 </div>
 </form>
 </div>
 </div>
</div>
