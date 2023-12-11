[% USE Koha %]
[% INCLUDE 'columns_settings.inc' %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="dialog message">
 [% IF report.modified_itemnumbers.size %]
 <span>[% report.modified_itemnumbers.size | html %] exemplar(es) modificado(s) (com [% report.modified_fields | html %] campos modificados).</span>
 [% ELSE %]
 <span>Nenhum exemplar modificado.</span>
 [% END %]

 [% IF job.status == 'cancelled' %]<span>A tarefa foi cancelada antes de terminar.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="Novo lote de modificação de exemplares">Novo lote de modificação de exemplares</a>
 </div>
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
 [% CASE %]<span>Mensagem desconhecida '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]

 [% IF too_many_items_display %]
 <p>Demasiados itens ([% report.modified_itemnumbers.size | html %]): Editou mais do que [% Koha.Preference('MaxItemsToDisplayForBatchMod') | html %] itens em lote, os mesmos não serão mostrados.</p>
 [% ELSIF items.size %]
 [% PROCESS items_table_batchmod headers => item_header_loop, items => items, display_columns_selection => 1 %]
 [% END %]
[% END %]

[% BLOCK js %]
 [% Asset.js("js/pages/batchMod.js") | $raw %]
[% END %]
