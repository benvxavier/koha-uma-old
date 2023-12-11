[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_holds == report.total_success %]
 <div class="dialog message">
 Todos as reservas foram canceladas com sucesso! </div>
 [% ELSE %]
 <div class="dialog message">
 <span>[% report.total_success | html %] / [% report.total_holds | html %] reservas modificadas com sucesso. Aconteceram alguns erros.</span>
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
 [% CASE 'hold_not_cancelled' %]
 [% IF m.biblio && m.patron %]
 <span>Reserva em <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% m.biblio.biblionumber | uri %]">[% m.biblio.title | html %]</a> para <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% m.patron.borrowernumber | uri %]">[% INCLUDE 'patron-title.inc' patron=m.patron %]</a> não foi cancelado.</span>
 [% END %]
 <span>Ocorreu um erro no cancelamento.</span>
 [% SWITCH m.error %]
 [% CASE 'hold_not_found' %]
 <span>Não foi encontrada a reserva com o id [% m.hold_id | html %].</span>
 [% CASE %]<span>Erro desconhecido '[% m.error | html %]'.</span>
 [% END %]
 [% CASE 'hold_cancelled' %]
 [% biblio_link = BLOCK %]<a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% m.biblio_id | uri %]">[% m.biblio.title | html %]</a>[% END %]
 [% patron_link = BLOCK %]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% m.patron_id | uri %]">[% INCLUDE 'patron-title.inc' patron=m.patron %]</a>[% END %]
 <span>Rserva em [% biblio_link | $raw | $KohaSpan %] para [% patron_link | $raw | $KohaSpan %] foi cancelada com sucesso.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
