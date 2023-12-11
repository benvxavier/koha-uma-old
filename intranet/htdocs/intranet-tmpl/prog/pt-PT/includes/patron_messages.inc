[% USE raw %]
[% USE Branches %]
[% SET ClaimReturnedWarningThreshold = Koha.Preference('ClaimReturnedWarningThreshold') %]
[% SET return_claims = patron.return_claims %]
[% SET logged_in_branchcode = Branches.GetLoggedInBranchcode() %]

[% IF ( has_modifications || warndeparture || returnbeforeexpiry || expired || patron.gonenoaddress || patron.lost || userdebarred || odues || ( return_claims.count > ClaimReturnedWarningThreshold ) || age_limitations || charges || charges_guarantors_guarantees || charges_guarantees || credits ) %]
 <h3>Atenção</h3>
 <ul>
 [% IF ( has_modifications ) %]
 <li class="has_modifications">
 <span class="circ-hlt">Modificações pendentes:</span>
 [% IF CAN_user_borrowers_edit_borrowers && ( !Koha.Preference('IndependentBranchesPatronModifications') || borrower.branch == branch ) %]
 <a href="/cgi-bin/koha/members/members-update.pl?active=[% patron.borrowernumber | uri %]">Rever modificações pendentes</a>
 [% ELSE %]
 <span>O leitor tem modificações pendentes</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( warndeparture ) %]
 <li class="warndeparture">
 <span class="circ-hlt">Fim:</span>
 <span>Patron's card expires on [% patron.dateexpiry | $KohaDates %].</span>
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">Renovar</a> ou <a href="/cgi-bin/koha/members/memberentry.pl?op=modify&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]">Editar detalhes </a>
 </li>
 [% END %]

 [% IF ( returnbeforeexpiry ) %]
 <li class="returnbeforeexpiry">
 <span class="circ-hlt">Definir a data em que expira :</span> Se tem a preferência de sistema ReturnBeforeExpiry activa significa que se a data de expiração é antes da data de término, a data de término passa a ser a data de expiração </li>
 [% END %]

 [% IF ( expired ) %]
 <li class="expired">
 <span class="circ-hlt">Fim:</span>
 <span>O cartão de leitor expirou.</span>
 [% IF ( expiry ) %]
 <span>O cartão de leitor expirou em [% expiry | $KohaDates %]</span>
 [% END %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">Renovar</a> ou <a href="/cgi-bin/koha/members/memberentry.pl?op=modify&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]">Editar detalhes </a>
 </li>
 [% END %]

 [% IF ( patron.gonenoaddress ) %]
 <li class="gonenoaddress blocker">
 <span title="o estado gonenoaddress está definido para este leitor"><span class="circ-hlt">Morada:</span> O endereço do leitor está marcado como em dúvida</span>
 </li>
 [% END %]

 [% IF ( patron.lost ) %]
 <li class="lost blocker">
 <span title="o estado perdido está definido para este leitor"><span class="circ-hlt">Perdido: </span> O cartão do leitor foi dado como perdido</span>
 </li>
 [% END %]

 [% IF ( userdebarred ) %]
 <li class="userdebarred blocker">
 <span class="circ-hlt"> Restrito desde [% debarredsince | $KohaDates %]:</span> A conta do leitor está suspensa [% IF ( userdebarreddate ) %] até [% userdebarreddate | $KohaDates %] [% END %] [% IF ( debarredcomment ) %] com a explicação: <br/>
 <em>
 [% IF debarredcomment.search('OVERDUES_PROCESS') %] Restrição adicionada pelo processo de atrasos [% debarredcomment.remove('OVERDUES_PROCESS ') | $raw | html_line_break %] [% ELSE %] [% debarredcomment | $raw | html_line_break %] [% END %] </em><br/>
 [% END %]
 <a class="btn btn-xs btn-default" href="#reldebarments-tab" onclick="$('#reldebarments-tab').click()"><i class="fa fa-ban"></i> Ver restrições</a>

 [% IF (noissues && CAN_user_circulate_force_checkout) %]
 <span class="override_debarment">
 <a href="/cgi-bin/koha/circ/circulation.pl?forceallow=1&amp;borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-xs btn-default">Ultrapassar a restrição temporariamente</a>
 </span>
 [% END %]
 </li> <!-- /.blocker -->
 [% END # /IF userdebarred %]

 [% IF ( odues ) %]
 <li class="odues blocker">
 <span class="circ-hlt">Atrasos:</span> O leitor tem EXEMPLARES EM ATRASO <a href="#checkouts">Ver os documentos em destaque abaixo</a>
 </li>
 [% END %]

 [% IF return_claims.count > ClaimReturnedWarningThreshold %]
 <li class="return_claims blocker">
 <span class="circ-hlt return-claims">Reclamações de devolução:</span> O leitor tem [% return_claims.count | html %] RECLAMAÇÕES DE DEVOLUÇÃO </li>
 [% END %]

 [% IF age_limitations %]
 [% INCLUDE 'category-out-of-age-limit.inc' %]
 [% END %]

 [% IF ( charges ) %]
 [% INCLUDE 'blocked-fines.inc' fines = chargesamount %]
 [% END %]

 [% IF ( charges_guarantors_guarantees ) %]
 <li class="charges_guarantors_guarantees">
 <span class="circ-hlt">Cobranças:</span> Os fiadores e os assegurados do leitores devem coletivamente [% charges_guarantors_guarantees | $Price %]. [% IF noissues %] <span class="circ-hlt">Empréstimos BLOQUEADOS porque as multas do leitor ULTRAPASSAM O LIMITE.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( charges_guarantees ) %]
 <li class="charges_guarantees">
 <span class="circ-hlt">Cobranças:</span> Os assegurados do leitores devem coletivamente [% chargesamount_guarantees | $Price %]. [% IF noissues %] <span class="circ-hlt">Empréstimos BLOQUEADOS porque as multas do leitor ULTRAPASSAM O LIMITE.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( credits ) %]
 <li class="credits">
 <span class="circ-hlt">Créditos:</span> Leitor tem um crédito[% IF ( creditsamount ) %] de <span class="credit"><strong>[% creditsamount | $Price %]</strong></span>[% END %]
 </li>
 [% END %]

 </ul>

[% END # /F ( has_modifications || warndeparture... %]

[% IF waiting_recalls.count %]
 <div id="recallswaiting" class="circmessage">
 [% SET waiting_here = 0 %]
 [% SET waiting_elsewhere = 0 %]
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 [% waiting_here = waiting_here + 1 %]
 [% ELSE %]
 [% waiting_elsewhere = waiting_elsewhere + 1 %]
 [% END %]
 [% END %]

 [% IF ( waiting_here > 0 ) %]
 <h4>Reclamações a aguardar aqui ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] por [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Reclamação feita por em [% w.created_date | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expiration_date %] À espera nesta biblioteca [% IF expires_on %] até [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>Reclamações por levantar noutras bibliotecas ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] por [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Reclamação feita por em [% w.created_date | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expiration_date %] À espera em [% Branches.GetName( w.pickup_library_id ) | html %] [% IF expires_on %] até [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 </div>
[% END # /IF waiting_recalls.count %]

[% IF WaitingHolds.count %]
 <div id="holdswaiting" class="circmessage">
 [% SET waiting_here = 0 %]
 [% SET waiting_elsewhere = 0 %]
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 [% waiting_here = waiting_here + 1 %]
 [% ELSE %]
 [% waiting_elsewhere = waiting_elsewhere + 1 %]
 [% END %]
 [% END %]

 [% IF ( waiting_here > 0 ) %]
 <h4>Reservas a aguardar aqui ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] por [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Reserva feita em [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expirationdate %] À espera nesta biblioteca [% IF expires_on %] até [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>Reservas por levantar noutras bibliotecas ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] por [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Reserva feita em [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expirationdate %] À espera em [% w.branch.branchname | html %] [% IF expires_on %] até [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 </div>
[% END # /IF WaitingHolds.count %]

[% IF Koha.Preference("CurbsidePickup") %]
 [% SET curbside_pickups = patron.curbside_pickups.search( branchcode => Branches.GetLoggedInBranchcode ) %]
 [% IF curbside_pickups.count %]
 <div id="curbside_pickups" class="circmessage">
 <h4>Levantamentos agendados aqui</h4>
 <ul>
 [% FOR cp IN curbside_pickups %]
 <li>Em [% cp.scheduled_pickup_datetime | $KohaDates %]: [% SWITCH cp.status %] [% CASE 'to-be-staged' %] <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=to-be-staged">
 A ser preparados</a>
 [% CASE 'staged-and-ready' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=staged-and-ready">
 Agendado e preparado</a>
 [% CASE 'patron-is-outside' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=patron-is-outside">
 O leitor está lá fora!</a>
 [% CASE 'delivered' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=delivered-today">
 Entregue</a>
 [% CASE %]<span>Estado desconhecido "[% cp.status | html %]"</span>
 [% END %]
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
[% END %]

[% IF ( patron.borrowernotes ) %]
 <div id="circnotes" class="circmessage">
 <h4>Notas</h4>
 <ul>
 <li>
 <span class="circ-hlt">
 [% patron.borrowernotes | $raw | html_line_break %]
 </span>
 </li>
 </ul>
 </div> <!-- /#circnotes -->
[% END # /IF patron.borrowernotes %]

[% IF ( patron_messages ) %]
 <div id="messages" class="circmessage">
 <h4>Mensagens</h4>
 <ul>
 [% FOREACH patron_message IN patron_messages %]
 <li>
 [% IF(patron_message.message_type == "L") %]
 <span class="circ-hlt">
 [% ELSE %]
 <span>
 [% END %]
 [% patron_message.message_date | $KohaDates %]
 [% Branches.GetName( patron_message.branchcode ) | html %]
 [% IF patron_message.manager_id %]
 ( <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% patron_message.manager_id | uri %]">[% patron_message.get_column('manager_firstname') | html %] [% patron_message.get_column('manager_surname') | html %]</a> )
 [% END %]
 <em>"[% patron_message.message | html %]"</em>
 [% IF patron_message.patron_read_date %] Lido: <em>[% patron_message.patron_read_date | $KohaDates %]</em>
 [% END %]
 </span>
 [% IF patron_message.branchcode == Branches.GetLoggedInBranchcode OR Koha.Preference('AllowAllMessageDeletion') %]
 [% IF moremember %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-target="#edit_message_form_[% patron_message.message_id | html %]" data-toggle="modal" class="btn btn-default"><i class="fa fa-edit"></i> Alterar</a>
 <a class="btn btn-link delete_message" href="/cgi-bin/koha/circ/del_message.pl?message_id=[% patron_message.message_id | html %]&amp;borrowernumber=[% patron_message.borrowernumber | html %]&amp;from=moremember"><i class="fa fa-trash"></i> Apagar</a>
 [% ELSE %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-target="#edit_message_form_[% patron_message.message_id | html %]" data-toggle="modal" class="btn btn-default"><i class="fa fa-edit"></i> Alterar</a>
 <a class="btn btn-link delete_message" href="/cgi-bin/koha/circ/del_message.pl?message_id=[% patron_message.message_id | html %]&amp;borrowernumber=[% patron_message.borrowernumber | html %]"><i class="fa fa-trash"></i> Apagar</a>
 [% END %]
 [% END %]
 </li>
 [% END %]
 </ul>
 <a id="addnewmessageLabel" href="#add_message_form" class="btn btn-link" data-toggle="modal"><i class="fa fa-plus"></i> Adicionar uma nova mensagem</a>
 </div> <!-- /#messages -->

 [% FOREACH pm IN patron_messages %]
 <div id="edit_message_form_[% pm.message_id | html %]" class="modal" tabindex="-1" role="dialog" aria-labelledby="#edit_message_form_[% patron_message.message_id | html %]" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="message_form" name="message_f">
 <input type="hidden" name="message_id" value="[% pm.message_id | html %]"/>
 <div class="modal-header">
 <h3>Editar mensagem</h3>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="message_type">A mensagem é para:</label>
 <select name="message_type" id="message_type" disabled>
 [% IF pm.message_type == "L" %]
 <option value="L" selected="selected">Nota interna</option>
 [% ELSE %]
 <option value="L">Nota interna</option>
 [% END %]

 [% IF pm.message_type == "B" %]
 <option value="B" selected="selected">OPAC - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% ELSE %]
 <option value="B">OPAC - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% END %]
 </select>
 </div>
 <div class="form-group">
 <textarea rows="3" class="modal-textarea" name="borrower_message" id="borrower_message" >[% pm.message | html %]</textarea>
 </div>
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> Guardar</button>
 <button class="btn btn-default deny cancel" href="#" data-dismiss="modal" aria-hidden="true"><i class="fa fa-times"></i> Anular</button>
 </div>
 </form>
 </div>
 </div>
 </div>
 [% END %]

[% END # /IF patron_messages %]
