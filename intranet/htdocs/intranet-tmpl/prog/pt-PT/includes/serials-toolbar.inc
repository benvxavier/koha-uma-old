[% INCLUDE 'blocking_errors.inc' %]
[% IF subscriptionid and ( CAN_user_serials_edit_subscription || CAN_user_serials_create_subscription || CAN_user_serials_receive_serials ) %]

 <div id="toolbar" class="btn-toolbar">
 [% IF CAN_user_serials_create_subscription %]
 [% IF biblionumber_for_new_subscription %]
 <div class="btn-group"><a id="newsubscription" class="btn btn-default" href="/cgi-bin/koha/serials/subscription-add.pl?biblionumber_for_new_subscription=[% biblionumber_for_new_subscription | html %]"><i class="fa fa-plus"></i> Nova assinatura para este periódico</a></div>
 [% ELSE %]
 <div class="btn-group"><a id="newsubscription" class="btn btn-default" href="/cgi-bin/koha/serials/subscription-add.pl"><i class="fa fa-plus"></i> Nova assinatura</a></div>
 [% END %]
 [% END %]

 [% IF ( CAN_user_serials_edit_subscription || CAN_user_serials_create_subscription || CAN_user_serials_delete_subscription ) %]
 [% UNLESS ( cannotedit ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-pencil"></i> Alterar <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_serials_edit_subscription ) %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-add.pl?op=modify&amp;subscriptionid=[% subscriptionid | uri %]">Modificar assinatura</a>
 </li>
 [% END %]

 [% IF ( CAN_user_serials_create_subscription ) %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-add.pl?op=dup&amp;subscriptionid=[% subscriptionid | uri %]">Editar como novo (duplicado)</a>
 </li>
 [% END %]

 [% IF CAN_user_editcatalogue_edit_catalogue %]
 <li>
 <a id="editbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber | uri %]">Modificar o registo</a>
 </li>
 [% END %]

 [% IF serialsadditems && CAN_user_editcatalogue_edit_items %]
 <li>
 <a id="edititems" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber | uri %]">Editar exemplares</a>
 </li>
 [% END %]

 [% IF ( CAN_user_serials_delete_subscription ) %]
 <li>
 <a href="#" id="deletesub">Eliminar assinatura</a>
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
 [% END %]

 [% IF not cannotedit or CAN_user_serials_receive_serials %]
 [% IF CAN_user_serials_renew_subscription and not closed %]
 <div class="btn-group"><a id="renew" class="btn btn-default" href="#"><i class="fa fa-refresh"></i> Renovar</a></div>
 [% END %]
 [% IF CAN_user_serials_receive_serials and not closed %]
 <div class="btn-group"><a id="receive" class="btn btn-default" href="/cgi-bin/koha/serials/serials-edit.pl?subscriptionid=[% subscriptionid | html %]&amp;serstatus=1,3"><i class="fa fa-inbox"></i> Receber</a></div>
 [% END %]
 [% UNLESS cannotedit %]
 [% IF closed %]
 <div class="btn-group"><a id="reopen" class="btn btn-default" href="#"><i class="fa fa-repeat"></i> Reabrir</a></div>
 [% ELSE %]
 <div class="btn-group"><a id="close" class="btn btn-default" href="#"><i class="fa fa-times-circle"></i> Fechar</a></div>
 [% END %]
 [% END %]
 [% END %]

 [% IF Koha.Preference('Mana') == 1 and Koha.Preference('AutoShareWithMana').grep('subscription').size == 0 %]
 [% IF one_language_enabled==0 or mana_id %]
 <div class="btn-group"><a class="btn btn-default" data-target="#mana_share_modal" data-toggle="modal" title="Partilhar a assinatura com outras bibliotecas. O seu endereço de email será associado com a partilha."><i class="fa fa-share-alt"></i> Partilhar</a></div>
 [% ELSE %]
 <div class="btn-group" data-toggle="tooltip" id="mana-subscription-share" title="Partilhar a assinatura com outras bibliotecas. O seu endereço de email será associado com a partilha."><a class="btn btn-default"><i class="fa fa-share-alt"></i> Partilhar</a></div>
 [% END %]
 [% END %]

 [% IF ( mana_id && Koha.Preference('Mana') == 1 ) %]
 <div class="btn-group">
 <button class="btn btn-default btn-sm dropdown-toggle" data-toggle="dropdown"> Reportar erro <span class="caret"></span></button>
 <ul class="dropdown-menu mana-actions">
 [% IF ( mana_comments ) %]
 [% FOREACH c IN mana_comments %]
 <li>
 <a data-commentid="[% c.id | html %]" data-resourceid="[% mana_id | html %]" href="#">[% c.message | html %] ([% c.nb | html %])</a>
 </li>
 [% END %]
 <li role="separator" class="divider"></li>
 [% END %]
 <li><a data-commentid="other" data-resourceid="[% mana_id | html %]" href="#">Novo comentário</a></li>
 </ul>
 </div>
 [% END %]
 </div>
[% ELSIF CAN_user_serials_create_subscription %]
 <div id="toolbar" class="btn-toolbar">
 [% IF ( biblionumber_for_new_subscription ) %]
 <div class="btn-group"><a id="newsubscription" class="btn btn-default" href="/cgi-bin/koha/serials/subscription-add.pl?biblionumber_for_new_subscription=[% biblionumber_for_new_subscription | html %]"><i class="fa fa-plus"></i> Nova assinatura para este periódico</a></div>
 [% ELSE %]
 <div class="btn-group"><a id="newsubscription" class="btn btn-default" href="/cgi-bin/koha/serials/subscription-add.pl"><i class="fa fa-plus"></i> Nova assinatura</a></div>
 [% END %]
 </div>
[% END %]

<div class="modal" id="mana-comment-box" tabindex="-1" role="dialog" aria-labelledby="mana_submit_comment">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <form id="mana_comment_form" action="/cgi-bin/koha/serials/subscription-detail.pl" method="get">
 <div class="modal-header">
 <button aria-label="Fechar" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 class="modal-title" id="mana_submit_comment">Insira uma novo comentário (máximo 35 caracteres)</h4>
 </div>
 <div class="modal-body">
 <input type="hidden" id="mana-resource" value="subscription" />
 <input type="hidden" id="mana-resource-id" value="[% mana_id | html %]" />
 <input type="text" maxlength="35" size="35" id="mana-comment" required="required" />
 <button id="mana-send-comment">Submeter</button>
 <a href="#" class="cancel" id="mana-comment-close">Anular</a>
 </div>
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-dismiss="modal">Fechar</button>
 </div>
 </form>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#mana-comment-box -->

<div id="mana_share_modal" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_share_modal_label">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="Fechar" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 id="mana_share_modal_label">Partilhar [% bibliotitle | html %] com o Mana</h4>
 </div>
 <div class="modal-body">
 [% IF (mana_id) %]
 <div class="alert">
 <p>A sua assinatura já se encontra ligada com um padrão de numeração no Mana. Partilhe-o se fez alguma alteração, caso contrário não será feita nenhuma alteração.</p>
 </div>
 [% END %]
 [% IF ( languages_loop ) %]
 [% UNLESS ( one_language_enabled ) %]
 <div class="rows">
 <ol>
 <li><span class="label">Periodicidade: </span>
 [% frequency.description | html %]
 </li>
 <li><span class="label">Padrão de numeração: </span>
 [% numberpattern.label | html %]
 </li>
 </ol>
 </div>
 <div class="rows">
 <form method="get" id="mana_share_form" action="/cgi-bin/koha/serials/subscription-detail.pl" class="validated" >
 <fieldset>
 <label for="mana_language">Idioma:</label>
 <select id="mana_language" name="mana_language">
 [% FOREACH languages_loo IN languages_loop %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.plural ) %]
 [% FOREACH sublanguages_loo IN languages_loo.sublanguages_loop %]
 [% IF ( sublanguages_loo.enabled ) %]
 [% IF ( sublanguages_loo.sublanguage_current ) %]
 <option value="[% languages_loo.rfc4646_subtag | html %]" selected>
 [% sublanguages_loo.native_description | html %]
 [% sublanguages_loo.script_description | html %]
 [% sublanguages_loo.region_description | html %]
 [% sublanguages_loo.variant_description | html %]
 ([% sublanguages_loo.rfc4646_subtag | html %])
 </option>
 [% ELSE %]
 <option value="[% languages_loo.rfc4646_subtag | html %]">
 [% sublanguages_loo.native_description | html %]
 [% sublanguages_loo.script_description | html %]
 [% sublanguages_loo.region_description | html %]
 [% sublanguages_loo.variant_description | html %]
 ([% sublanguages_loo.rfc4646_subtag | html %])
 </option>
 [% END %]
 [% END %]
 [% END %]
 [% ELSE %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.current ) %]
 <option value="[% languages_loo.rfc4646_subtag | html %]" selected>
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </option>
 [% ELSE %]
 <option value="[% languages_loo.rfc4646_subtag | html %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </option>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </select>
 <input type="hidden" id="op" name="op" value="share"/>
 <input type="hidden" id="subscriptionid" name="subscriptionid" value="[% subscriptionid | html %]"/>
 </fieldset>
 </form>
 </div> <!-- /.rows -->
 [% END %]
 [% END %]
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <button type="submit" form="mana_share_form" class="btn btn-default">Partilhar</button>
 <button class="btn btn-default" data-dismiss="modal" aria-hidden="true">Anular</button>
 </div>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#mana-share-modal -->
