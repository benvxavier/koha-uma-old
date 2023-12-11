[% USE Koha %]

[% SET report = job.decoded_data %]
[% BLOCK report %]
 [% IF job.status == 'finished' %]
 [% IF report %]
 <div class="dialog message">
 [% report.record_ids.size | html %] registos foram reindexados com sucesso. </div>
 [% ELSE %]
 <div class="dialog message">
 Não foi possível ler os dados da tarefa, veja os logs para mais detalhes </div>
 [% END %]
 [% ELSIF job.status == 'cancelled' %]
 <span>A tarefa foi cancelada antes de terminar.</span>
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
 [% END %] [% SWITCH m.code %] [% CASE 'index_error' %] Ocorreu um erro durante o processo de indexação: [% m.error | html %] [% END %] </div>
 [% END %]
 [% IF report %]
 <h3> Identificadores:</h3>
 <ul>
 [% FOREACH record_id IN report.record_ids %]
 <li><a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% record_id | uri %]">[% record_id | html %]</a></li>
 [% END %]
 </ul>
 [% END %]
[% END %]


[% BLOCK js %]
[% END %]
