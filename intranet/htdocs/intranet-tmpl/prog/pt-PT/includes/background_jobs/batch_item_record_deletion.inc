[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="dialog message">
 [% IF report.deleted_itemnumbers.size %]
 <p>[% report.deleted_itemnumbers.size | html %] documento(s) eliminado(s)</p>
 [% IF report.deleted_biblionumbers.size %]
 <p>[% report.deleted_biblionumbers.size | html %] documento(s) eliminado(s).</p>
 [% END %]
 [% ELSE %]
 <p>Nenhum exemplar eliminado.</p>
 [% END %]
 </div>

 [% IF report.not_deleted_itemnumbers.size %]
 <div class="dialog error">
 [% report.not_deleted_itemnumbers.size | html %] exemplar(es) não eliminado(s): [% FOREACH not_deleted_itemnumber IN report.not_deleted_itemnumbers %][% not_deleted_itemnumber | html %] [% END %] </div>
 [% END %]

 [% IF job.status == 'cancelled' %]
 <div class="dialog error">
 <span>A tarefa foi cancelada antes de terminar.</span>
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="Novo lote de modificação de exemplares">Novo lote de modificação de exemplares</a>
 </div>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
 [% FOR m IN job.messages %]
 <div class="dialog message">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa fa-warning warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'item_not_deleted' %]
 [% item_link = BLOCK %]<a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% m.biblionumber | uri %]&itemnumber=[% m.itemnumber | uri %]">[% m.barcode | html %]</a>[% END %]
 <span>O exemplar com o código de barras [% item_link | $raw | $KohaSpan%] não pode ser eliminado:</span>
 [% SWITCH m.reason %]
 [% CASE "book_on_loan" %]<span>O exemplar está emprestado</span>
 [% CASE "not_same_branch" %]<span>O exemplar não pertence à sua biblioteca</span>
 [% CASE "book_reserved" %]<span>O exemplar tem uma reserva em espera</span>
 [% CASE "linked_analytics" %]<span>O exemplar está em uso por analíticos</span>
 [% CASE "last_item_for_hold" %]<span>Último exemplar de um registo com uma reserva ao nível de registo</span>
 [% CASE %]<span>Causa desconhecida '[% m.reason | html %]'</span>
 [% END %]
 [% CASE %]<span>Mensagem desconhecida '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
