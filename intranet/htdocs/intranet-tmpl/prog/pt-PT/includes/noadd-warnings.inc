[% IF ( no_add ) %]
 <div class="dialog alert">
 <h3>Não é possível adicionar o leitor</h3>
 [% IF ( no_branches ) %]
 <p><strong>Não existem bibliotecas definidas. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/branches.pl">Por favor adicione uma biblioteca</a>.[% ELSE %]O administrador deve definir pelo menos uma biblioteca.[% END %]</p>
 [% END %]
 [% IF ( no_categories ) %]
 <p><strong>Não existem categorias de leitor definidas. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/categories.pl">Por favor adicione uma categoria de leitor</a>.[% ELSE %]O administrador deve definir pelo menos uma categoria de leitor.[% END %]</p>
 [% END %]
 </div>
[% END %]
