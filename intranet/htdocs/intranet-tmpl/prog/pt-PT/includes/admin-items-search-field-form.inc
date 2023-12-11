[% PROCESS 'html_helpers.inc' %]
<ol>
 <li>
 [% IF field %]
 <span class="label">Nome: </span>
 [% field.name | html %]
 <input type="hidden" name="name" value="[% field.name | html %]">
 [% ELSE %]
 <label class="required" for="name">Nome: </label>
 <input type="text" name="name" id="name" class="required" required="required" />
 <span class="required">Obrigatório</span>
 [% END %]
 </li>
 <li>
 <label class="required" for="label">Etiqueta: </label>
 <input type="text" name="label" id="label" value="[% field.label | html %]" class="required" required="required" />
 <span class="required">Obrigatório</span>
 </li>
 <li>
 <label class="required" for="tagfield">Campo MARC: </label>
 <input type="text" id="tagfield" name="tagfield" maxlength="3" size="3" class="required" pattern="[a-zA-Z0-9]+" required="required" value="[% field.tagfield | html %]" />
 <span class="required">Obrigatório</span>
 </li>
 <li>
 <label for="tagsubfield">Subcampo MARC: </label>
 <input type="text" id="tagsubfield" name="tagsubfield" pattern="[a-zA-Z0-9]+" maxlength="1" size="1" value="[% field.tagsubfield | html %]" />
 </li>
 <li>
 <label for="authorised_values_category">Categoria de valor autorizado: </label>
 <select id="authorised_values_category" name="authorised_values_category">
 <option value="">- Nenhum -</option>
 [% PROCESS options_for_authorised_value_categories authorised_value_categories => AuthorisedValues.GetCategories( selected => field.authorised_values_category ) %]
 </select>
 </li>
</ol>
