 [% IF item_action_ignore AND num_items == 0 %] Não foram encontrados exemplares durante a preparação <input type ="hidden" name="item_action" value="ignore">
 [% ELSE %]
 <select name="item_action" id="item_action">
 [% IF ( item_action_always_add ) %]
 <option value="always_add" selected="selected">
 [% ELSE %]
 <option value="always_add">
 [% END %] Adicionar sempre os exemplares</option>
 [% IF ( item_action_add_only_for_matches ) %]
 <option value="add_only_for_matches" selected="selected">
 [% ELSE %]
 <option value="add_only_for_matches">
 [% END %] Adicionar exemplares apenas se for encontrado um registo bibliográfico correspondente</option>
 [% IF ( item_action_add_only_for_new ) %]
 <option value="add_only_for_new" selected="selected">
 [% ELSE %]
 <option value="add_only_for_new">
 [% END %] Adicionar exemplares apenas se não for encontrado um registo bibliográfico correspondente</option>
 [% IF ( item_action_replace ) %]
 <option value="replace" selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Substituir exemplares se um registo correspondente for encontrado (apenas para exemplares existentes)</option>
 [% IF ( item_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Ignorar itens</option>
 </select>
 [% END %]
