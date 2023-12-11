[% USE Koha %]
[% USE Branches %]
[% PROCESS 'html_helpers.inc' %]
<ol>
 <li><label for="title">Título: </label> <input type="text" name="title" id="title" value="[% filters.title | html %]" /></li>
 <li><label for="author">Autor: </label> <input type="text" name="author" id="author" value="[% filters.author | html %]" /></li>
 <li><label for="isbn">ISBN: </label> <input type="text" name="isbn" id="isbn" value="[% filters.isbn | html %]" /></li>
 <li><label for="isbn">ISSN: </label> <input type="text" name="issn" id="issn" value="[% filters.issn | html %]" /></li>
 [% IF Koha.Preference('marcflavour') == 'UNIMARC' %]
 <li><label for="ean">EAN: </label> <input type="text" name="ean" id="ean" value="[% filters.ean | html %]" /></li>
 [% END %]
 <li><label for="name">Fornecedor: </label> <input type="text" name="name" id="name" value="[% filters.name | html %]" /></li>
 <li><label for="basket">Cesto: </label> <input type="text" name="basket" id="basket" value="[% filters.basket | html %]" /></li>
 <li><label for="internalnote">Nota interna: </label> <input type="text" name="internalnote" id="internalnote" value="[% filters.internalnote | html %]" /></li>
 <li><label for="vendornote">Nota do fornecedor: </label> <input type="text" name="vendornote" id="vendornote" value="[% filters.vendornote | html %]" /></li>
 <li><label for="basket_creators">Cesto criado por: </label>
 <input autocomplete="off" id="find_patron" type="text" class="noEnterSubmit" />
 <div>
 <div id="basket_creators" style="float:left;"></div>
 </div>
 </li>
 <li>
 <label for="managing_library">Biblioteca (gestão): </label>
 <select name="managing_library" id="managing_library">
 <option value="">Qualquer biblioteca</option>
 [% PROCESS options_for_libraries libraries => Branches.all(selected => '') %]
 </select>
 </li>
 <li><label for="booksellerinvoicenumber ">Número da fatura do fornecedor: </label> <input type="text" name="booksellerinvoicenumber" id="booksellerinvoicenumber" value="[% filters.booksellerinvoicenumber | html %]" /></li>
 <li>
 <label for="basketgroupname">Grupo de cestos:</label>
 <input type="text" name="basketgroupname" id="basketgroupname" value="[% filters.basketgroupname | html %]" />
 </li>
 [% INCLUDE 'additional-fields-entry.inc' available=available_additional_fields values=additional_field_filters wrap_fieldset=0 %]
 <li>
 <label for="ordernumber">Linha de encomenda :</label>
 <input type="text" name="ordernumber" id="ordernumber" value="[% filters.ordernumber | html %]" />
 <label class="yesno" for="search_children_too">
 [% IF filters.search_children_too %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" />
 [% END %] Mostrar crianças também </label>
 </li>

 <li>
 <label for="orderstatus">Estado da encomenda: </label>
 <select name="orderstatus" id="orderstatus">
 [% IF filters.orderstatus == "" %]
 <option value="">Qualquer estado excepto cancelado</option>
 [% ELSE %]
 <option value="" selected="selected"></option>
 [% END %]
 [% IF filters.orderstatus == "new" %]
 <option value="new" selected="selected">Novo</option>
 [% ELSE %]
 <option value="new">Novo</option>
 [% END %]
 [% IF filters.orderstatus == "ordered" %]
 <option value="ordered" selected="selected">Encomendado</option>
 [% ELSE %]
 <option value="ordered">Encomendado</option>
 [% END %]
 [% IF filters.orderstatus == "partial" %]
 <option value="partial" selected="selected">Recebida parcialmente</option>
 [% ELSE %]
 <option value="partial">Recebida parcialmente</option>
 [% END %]
 [% IF filters.orderstatus == "complete" %]
 <option value="complete" selected="selected">Recebido</option>
 [% ELSE %]
 <option value="complete">Recebido</option>
 [% END %]
 [% IF filters.orderstatus == "cancelled" %]
 <option value="cancelled" selected="selected">Cancelado</option>
 [% ELSE %]
 <option value="cancelled">Cancelado</option>
 [% END %]
 </select>
 <label class="yesno" for="search_children_too">
 [% IF filters.is_standing %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" />
 [% END %] Encomenda ativa </label>
 </li>
 <li>
 <label for="fund">Fundo: </label>
 <select name="budget" id="fund">
 <option value="">Todos os fundos</option>
 [% FOREACH bp_loo IN bp_loop %]
 <optgroup label="[% bp_loo.budget_period_description | html %]">
 [% FOREACH h_loo IN bp_loo.hierarchy %]
 [% IF h_loo.budget_id == filters.budget %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]" selected="selected">
 [% ELSE %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]">
 [% END %]
 [% h_loo.budget_display_name | html %]
 </option>
 [% END %]
 </optgroup>
 [% END %]
 </select>
 </li>

 <li><label for="from">De: </label>
 <input type="text" size="10" id="from" name="from" value="[% filters.from_placed_on | html %]" class="flatpickr" data-date_to="to" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
 <li><label for="to">Para: </label>
 <input type="text" size="10" id="to" name="to" value="[% filters.to_placed_on | html %]" class="flatpickr" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
</ol>
