[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">Importação de registos concluída</div>
 [% END %]

 <h2>Resultados da preparação MARC</h2>
 [% SWITCH job.decoded_data.record_type %]
 [% CASE 'biblio' %]
 <h3>A processar os registos bibliográficos</h3>
 [% CASE 'auth' %]
 <h3>A processar os registos de autoridade</h3>
 [% END %]
 <ul>
 <li>[% report.total | html %] registo(s) no ficheiro</li>
 <li>[% report.import_errors | html %] registo(s) não aceite(s) devido a um erro do formato MARC</li>
 <li>[% report.staged | html %] registo(s) preparado(s)</li>
 [% IF ( report.checked_matches ) %]
 <li>[% report.matched | html %] registo(s) com pelo menos um duplicado no catálogo com correspondência a &quot;[% report.matcher_code | html %]&quot;</li>
 [% ELSE %]
 [% IF ( report.matcher_failed ) %]
 <li>Regra de concordância falhou -- impossível retornar a regra de concordância seleccionada.</li>
 [% ELSE %]
 <li>Não verificar por correspondências com os registos do catálogo</li>
 [% END %]
 [% END %]
 [% IF report.record_type == 'biblio' %]
 <li>[% report.num_items | html %] registo(s) encontrado(s) e importado(s)</li>
 [% END %]
 [% IF ( report.label_batch ) %]
 <li>Novo lote de etiquetas criado: n° [% report.label_batch | html %] </li>
 [% END %]
 </ul>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | uri %]">Ver lote</a>
 </p>
 [% IF report.basket_id && report.vendor_id %]
 <p>
 <a id="addtobasket" class="btn btn-default" href="/cgi-bin/koha/acqui/addorderiso2709.pl?import_batch_id=[% report.import_batch_id | html %]&basketno=[% report.basket_id | html %]&booksellerid=[% report.vendor_id | html %]">Adicionar ficheiros ao cesto</a>
 </p>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
