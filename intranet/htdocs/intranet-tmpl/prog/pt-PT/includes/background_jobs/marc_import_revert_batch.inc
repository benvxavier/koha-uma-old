[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">Sucesso: Importação revertida</div>
 [% END %]
 <table>
 <tr>
 <td>Total de registos eliminados</td>
 <td>[% report.num_deleted | html %]</td>
 </tr>
 <tr>
 <td>Número de registos revertidos</td>
 <td>[% report.num_reverted | html %]</td>
 </tr>
 <tr>
 <td>Total de registos ignorados</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Número de exemplares eliminados</td>
 <td>[% report.num_items_deleted | html %]</td>
 </tr>
 <tr>
 <td>Número de erros</td>
 <td>[% report.num_errors | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Gerir lote revertido</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
