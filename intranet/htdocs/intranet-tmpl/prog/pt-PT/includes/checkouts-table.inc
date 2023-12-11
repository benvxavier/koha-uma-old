[% USE Koha %]
[% PROCESS 'modal-claims.inc' %]
[% INCLUDE 'format_price.inc' %]

[% IF ( issuecount ) %]
 <div id="issues-table-loading-message">
 <p>
 <a id="issues-table-load-now-button" href="#" class="btn btn-default"><i class="fa fa-book"></i> Mostrar empréstimos</a>
 </p>
 </div>
 <form name="issues" action="/cgi-bin/koha/tools/export.pl" method="post">
 <table id="issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">&nbsp;</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Data de devolução</th>
 <th scope="col">Data de devolução</th>
 <th scope="col">Título</th>
 <th scope="col">Tipo de documento do registo</th>
 <th scope="col">Tipo de documento</th>
 <th scope="col">Coleção</th>
 <th scope="col">Localização</th>
 <th scope="col">Biblioteca de inscrição</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Emprestado em</th>
 <th scope="col">Emprestado desde</th>
 <th scope="col">Cota</th>
 <th scope="col">Número de cópia</th>
 <th scope="col">Custo</th>
 <th scope="col">Multa</th>
 <th scope="col">Preço</th>
 <th scope="col">Renovar <p class="column-tool"><a href="#" id="CheckAllRenewals">seleccionar todos</a> | <a href="#" id="UncheckAllRenewals">nenhum</a></p></th>
 <th scope="col">Devolver <p class="column-tool"><a href="#" id="CheckAllCheckins">seleccionar todos</a> | <a href="#" id="UncheckAllCheckins">nenhum</a></p></th>
 <th scope="col">Reclamações de devolução</th>
 <th scope="col">Exportar <p class="column-tool"><a href="#" id="CheckAllExports">seleccionar todos</a> | <a href="#" id="UncheckAllExports">nenhum</a></p></th>
 </tr>
 </thead>
 [% INCLUDE 'checkouts-table-footer.inc' %]
 </table>

 <label for="issues-table-load-immediately">Mostrar automaticamente os empréstimos</label>
 <input id="issues-table-load-immediately" type="checkbox" />

 <div id="issues-table-actions">
 <fieldset class="action">
 [% IF ( CAN_user_circulate_override_renewals ) %]
 [% IF Koha.Preference( 'AllowRenewalLimitOverride' ) || Koha.Preference( 'AllowRenewalOnHoldOverride' ) %]
 <label for="override_limit">Sobrepor limite de renovação:</label>
 <input type="checkbox" name="override_limit" id="override_limit" value="1" />
 [% END %]
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF Koha.Preference( 'UnseenRenewals' ) %]
 <label id="renew_as_unseen_label" for="override_limit">Renovar como &quot;não visto&quot; se adequado:</label>
 <input type="checkbox" name="renew_as_unseen" id="renew_as_unseen_checkbox" value="1" />
 [% END %]
 <button class="btn btn-default" id="RenewCheckinChecked"><i class="fa fa-check"></i> Renovar ou devolver o(s) documento(s) selecionado(s)</button>
 <button class="btn btn-default" id="RenewAll"><i class="fa fa-book"></i> Renovar todos</button>
 [% END %]
 </fieldset>

 [% IF Koha.Preference('ExportCircHistory') %]
 <fieldset>
 <label for="issues-table-output-format"><strong>Exportar empréstimos com o formato:</strong></label>
 <select name="issues-table-output-format" id="issues-table-output-format">
 <option value="iso2709_995">MARC com exemplares</option>
 <option value="iso2709">MARC sem exemplares</option>
 [% IF csv_profiles.count %]
 <option value="csv">CSV</option>
 [% END %]
 </select>

 [% IF csv_profiles.count %]
 <select name="csv_profile_id">
 [% FOREACH csv_profile IN csv_profiles %]
 <option value="[% csv_profile.export_format_id | html %]">[% csv_profile.profile | html %]</option>
 [% END %]
 </select>
 [% END %]
 <label for="export_items_bundle_contents">Exportar conteúdo do conjunto de exemplares</label> <input type="checkbox" name="export_items_bundle_contents" id="export_items_bundle_contents">
 <label for="export_remove_fields">Não exportar campos:</label> <input id="export_remove_fields" name="export_remove_fields" title="Usar para exportações MARC" type="text" value="[% Koha.Preference('ExportRemoveFields') | html %]" />
 <input type="hidden" name="op" value="export" />
 <input type="hidden" id="output_format" name="output_format" value="iso2709" />
 <input type="hidden" id="dont_export_item" name="dont_export_item" value="0" />
 <input type="hidden" id="record_type" name="record_type" value="bibs" />
 <button class="btn btn-default btn-sm" id="export_submit"><i class="fa fa-download"></i> Exportar</button>
 </fieldset>
 [% END %]
 </div>
 </form>
[% ELSE %]
 <p>Leitor não tem nada emprestado.</p>
[% END %]

<!-- Claims Returned Modal -->
[% PROCESS 'modal-claims-display' %]
