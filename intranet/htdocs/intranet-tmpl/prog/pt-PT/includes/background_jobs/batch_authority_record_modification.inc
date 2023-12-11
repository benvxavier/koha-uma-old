[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 Todos os registos foram modificados com sucesso! <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="Novo lote de modificação de registos">Novo lote de modificação de registos</a>
 </div>
 [% ELSE %]
 <div class="dialog message">
 <span>[% report.total_success | html %] / [% report.total_records | html %] registos modificados com sucesso. Aconteceram alguns erros.</span>
 [% IF job.status == 'cancelled' %]<span>A tarefa foi cancelada antes de terminar.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="Novo lote de modificação de registos">Novo lote de modificação de registos</a>
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
 [% authority_link = BLOCK %]<a href="/cgi-bin/koha/authorities/detail.pl?authid=[% m.authid | uri %]">[% m.authid | html %]</a>[% END %]
 [% SWITCH m.code %]
 [% CASE 'authority_not_modified' %]
 <span>O registo de autoridade [% authority_link | $raw | $KohaSpan %] não foi modificado. Ocorreu um erro na modificação</span>
 [% IF m.error %] ([% m.error | html %])[% END %].
 [% CASE 'authority_modified' %]
 <span>O registo de autoridade [% authority_link | $raw | $KohaSpan %] foi modificado com sucesso.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
