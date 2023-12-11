[% USE KohaDates %]
[% USE Koha %]
[% USE AuthorisedValues %]
[% USE Branches %]
[% USE raw %]

[% IF statuscode == "200" %]
 [% INCLUDE 'mana/mana-comment-status.inc' %]
 <div id="mana_results">
 <table id="mana_results_datatable">
 <thead>
 <tr>
 <th>ISSN</th>
 <th class="anti-the">Título</th>
 <th> Publicado por </th>
 <th>Periodicidade</th>
 <th>Modelo de numeração</th>
 <th title="Número de bibliotecas a usar este padrão"># de leitores</th>
 <th title="Última vez que uma biblioteca usou este padrão">Última importação</th>
 <th> Comentários </th>
 [% UNLESS search_only %]
 <th class="NoSort noExport">Ações</th>
 [% END %]
 </tr>
 </thead>
 <tbody>
 [% FOREACH subscription IN subscriptions %]
 [% UNLESS subscription.cannotdisplay %]
 [% IF subscription.nbofcomment > highWarned  %]
 <tr class="high-warned-row" id="row[% subscription.id | html %]" title="Este recurso já foi reportado mais do que [% highWarned | html %] vezes, tenha cuidado!">
 [% ELSIF subscription.nbofcomment > warned  %]
 <tr class="warned-row" id="row[% subscription.id | html %]" title="Este recurso já foi reportado mais do que [% warned | html %] vezes, tenha cuidado!">
 [% ELSIF subscription.nbofcomment > lowWarned  %]
 <tr class="highlighted-row" id="row[% subscription.id | html %]" title="Este recurso já foi reportado mais do que [% lowWarned | html %] vezes, tenha cuidado!">
 [% ELSE %]
 <tr id="row[% subscription.id | html %]">
 [% END %]
 <input type="hidden" hidden class="rowid" value="[% subscription.id | html %]" />
 <td>[% IF ( subscription.issn ) %][% subscription.issn | html %][% END %]</td>
 <td>[% subscription.title | html %]</td>
 <td>[% IF ( subscription.publishercode ) %][% subscription.publishercode | html %][% END %]</td>
 <td>[% IF ( subscription.sfdescription ) %][% subscription.sfdescription | html %][% END %]</td>
 <td>[% IF ( subscription.numberingmethod ) %][% subscription.numberingmethod | html %][% END %]</td>
 <td>[% IF ( subscription.nbofusers ) %][% subscription.nbofusers | html %][% END %]</td>
 <td data-order="[% subscription.lastimport | html %]">[% subscription.lastimport | $KohaDates %]</td>
 <td>
 [% FOREACH comment IN subscription.comments %]
 [% comment.message | html %] ([% comment.nb | html %])<br />
 [% END %]
 </td>
 [% UNLESS search_only %]
 <td class="actions">
 <button class="btn btn-default btn-xs mana-use" data-subscription_id="[% subscription.id | html %]" id="mana-use-[% subscription.id | html %]"><i class="fa fa-download"></i> Importar</button>
 <div class="dropup">
 <button type="button" class="btn btn-default btn-xs dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
 Relatório <span class="caret"></span>
 </button>
 <ul class="dropdown-menu pull-right mana-actions" id="mana-actions-[% subscription.id | html %]">
 [% IF ( subscription.comments.size ) %]
 [% FOREACH comment IN subscription.comments %]
 <li><a data-commentid="[% comment.id | html %]" data-resourceid="[% subscription.id | html %]" href="#">[% comment.message | html %] ([% comment.nb | html %])</a></li>
 [% END %]
 <li role="separator" class="divider"></li>
 [% END %]
 <li><a data-commentid="other" data-resourceid="[% subscription.id | html %]" href="#">Novo comentário</a></li>
 </ul>
 </div>
 </td>
 [% END %]
 </tr>
 [% END %]
 [% END %]
 </tbody>
 </table>
 </div>
 <div id="new_mana_comment" style="display:none">
 <h4 id="mana_submit_comment"> Insira uma novo comentário (máximo 35 caracteres)</h4>
 <form id="mana_comment_form" action="/cgi-bin/koha/serials/subscription-detail.pl" method="get">
 <input type="hidden" id="mana-resource" value="subscription" />
 <input type="hidden" id="mana-resource-id" value="[% mana_id | html %]" />
 <input type="text" maxlength="35" size="35" id="mana-comment" required="required" />
 <input type="hidden" id="selected_id" value="" />
 <div class="action">
 <button id="mana-send-comment">Submeter</button>
 <a href="#" class="cancel" id="mana-comment-close">Anular</a>
 </div>
 </form>
 </div>
[% ELSE %]
 <h4>A pesquisa falhou com o código: [% statuscode | html %] </h4>
[% END %]

<div id="comment_box" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_search_result_label" style="display: none;">
 <div class="modal-dialog modal-lg" style="width: 30%">
 <div class="modal-content" style="">
 <div class="modal-header">
 <button type="button" id="commentCloseButton" class="closebtn" aria-hidden="true">×</button>
 <h3 id="mana_submit_comment"> Insira uma novo comentário (máximo 35 caracteres)</h3>
 </div>
 <div class="modal-body">
 <form>
 <input hidden id="selected_id" value="">
 <input type="text" id="manamsg"> Comentário: </form>
 <button id="CommentButton"> Comentário </button>
 </div>
 </div>
 </div>
</div>
