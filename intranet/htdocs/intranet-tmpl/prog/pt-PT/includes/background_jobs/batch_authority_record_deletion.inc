[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 Todos os registos foram eliminados com sucesso! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="dialog message">
 Nenhum registo foi eliminado. Ocorreu um erro. </div>
 [% ELSE %]
 <div class="dialog message">
 [% report.total_success | html %] / [% report.total_records | html %] registos foram eliminados com sucesso mas alguns erros ocorreram. </div>
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
 [% IF m.code == 'authority_not_exists' %]
 <span>O registo de autoridade [% m.authid | html %] não existe na base de dados.</span>
 [% ELSIF m.code == 'authority_not_deleted' %]
 <span>O registo de autoridade [% m.authid | html %] não foi eliminado. Ocorreu um erro.</span>
 [% ELSIF m.code == 'authority_deleted' %]
 <span>A autoridade [% m.authid | html %] foi eliminada com sucesso.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
