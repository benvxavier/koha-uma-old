[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_biblios == report.total_success %]
 <div class="dialog message">
 Fila de espera das reservas atualizada com sucesso. </div>
 [% ELSE %]
 <div class="dialog message">
 <span>Fila de reservas para [% report.total_success | html %] / [% report.total_biblios | html %] foi atualizada com sucesso. Aconteceram alguns erros.</span>
 [% IF job.status == 'cancelled' %]<span>A tarefa foi cancelada antes de terminar.</span>[% END %]
 </div>
 [% END %]
 [% END %]

[% END %]

[% BLOCK detail %]
 [% FOR m IN report_messages %]
 <div class="dialog message">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa fa-warning warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'holds_queue_update_error' %]
 [% IF m.biblio_id %]
 <span>Fila de reservas para o registo <a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% m.biblio_id | uri %]">[% m.biblio.title | html %]</a>.</span>
 [% END %]
 <span>Ocorreu um erro ([% m.error | html %])</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
