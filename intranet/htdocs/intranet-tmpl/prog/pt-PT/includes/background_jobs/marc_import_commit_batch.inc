[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">Importação de registos concluída</div>
 [% END %]
 <table>
 <tr>
 <td>Total de registos adicionados</td>
 <td>[% report.num_added | html %]</td>
 </tr>
 <tr>
 <td>Total de registos atualizados</td>
 <td>[% report.num_updated | html %]</td>
 </tr>
 <tr>
 <td>Total de registos ignorados</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Número de exemplares adicionados</td>
 <td>[% report.num_items_added | html %]</td>
 </tr>
 <tr>
 <td>Número de exemplares alterados</td>
 <td>[% report.num_items_replaced | html %]</td>
 </tr>
 <tr>
 <td>Total de exemplares ignorados</td>
 <td>[% report.num_items_errored | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Gerir lote importado</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
