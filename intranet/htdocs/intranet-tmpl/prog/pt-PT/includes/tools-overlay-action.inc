 <select name="overlay_action" id="overlay_action">
 [% IF ( overlay_action_replace ) %]
 <option value="replace"  selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Sobrepor o registo existente com o novo registo</option>
 [% IF ( overlay_action_create_new ) %]
 <option value="create_new" selected="selected">
 [% ELSE %]
 <option value="create_new">
 [% END %] Adicionar um registo</option>
 [% IF ( overlay_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Ignorar os registos a caminho (os seus itens precisam de ser processados)</option>
 </select>
