[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report && job.status != 'started' && job.status != 'new' %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 Todos os títulos eleectrónicos foram criados com sucesso! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="dialog message">
 Nenhum título electrónico foi criado. Ocorreu um erro. </div>
 [% ELSE %]
 <div class="dialog message">
 [% report.total_success | html %] / [% report.total_records | html %] títulos electrónicos foram criados com sucesso mas alguns erros ocorreram. </div>
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
 [% CASE 'package_do_not_exist' %]
 <span>O pacote #[% m.package_id | html %] não existe.</span>
 [% CASE 'biblio_already_exists' %]
 <span>O registo bibliográfico ([% m.biblio_id | html %]) já existe neste pacote (<a href="/cgi-bin/koha/erm/eholdings/local/resources/[% m.resource_id | uri %]">recurso #[% m.resource_id | html %]</a>)</span>
 [% CASE 'eholding_not_created' %]
 <span>Não foi possível criar o título electrónico a partir do registo bibliográfico #[% m.biblio_id | html %], ocorreu o seguinte erro: [% m.error | html %].</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
