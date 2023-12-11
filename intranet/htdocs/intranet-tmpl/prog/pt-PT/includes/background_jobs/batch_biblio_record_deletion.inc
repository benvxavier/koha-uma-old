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
 [% SWITCH m.code %]
 [% CASE 'biblio_not_exists' %]
 <span>O registo [% m.biblionumber | html %] não existe na base de dados.</span>
 [% CASE 'item_issued' %]
 <span>Pelo menos um exemplar do registo bibliográfico [% m.biblionumber | html %] está emprestado.</span>
 [% CASE 'reserve_not_cancelled' %]
 <span>O registo bibliográfico [% m.biblionumber | html %] não foi eliminado. Não foi possível cancelar uma reserva (reserva [% m.reserve_id | html %]).</span>
 [% CASE 'item_not_deleted' %]
 <span>O registo bibliográfico [% m.biblionumber | html %] não foi eliminado. Ocorreu um erro ao eliminiar um exemplar (número de exemplar [% m.itemnumber | html %]).</span>
 [% CASE 'biblio_not_deleted' %]
 <span>O registo bibliográfico [% m.biblionumber | html %] não foi eliminado. Ocorreu um erro.</span>
 [% CASE 'biblio_deleted' %]
 <span>O registo bibliográfico [% m.biblionumber | html %] foi eliminado com sucesso.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
