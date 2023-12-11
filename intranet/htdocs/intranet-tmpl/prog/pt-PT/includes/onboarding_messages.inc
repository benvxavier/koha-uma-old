[% FOR m IN messages %]
 [% SWITCH m.code %]
 [% CASE 'success_on_insert_library' %]
 <div class="alert alert-success">Biblioteca criada!</div>
 [% CASE 'error_on_insert_library' %]
 <div class="alert alert-danger">A biblioteca já existe e não pode ser modificada!</div>
 [% CASE 'success_on_insert_category' %]
 <div class="alert alert-success">Categoria de leitor criada!</div>
 [% CASE 'error_on_insert_category' %]
 <div class="alert alert-danger">A categoria de leitor já existe e não pode ser modificada!</div>
 [% CASE 'success_on_insert_patron' %]
 <div class="alert alert-success">Leitor de administração criado!</div>
 [% CASE 'error_on_insert_patron' %]
 <div class="alert alert-danger">O campo não foi adicionado! O nome de utilizador ou o número de cartão já existe.</div>
 [% CASE 'ERROR_cardnumber_already_exists' %]
 <div class="alert alert-danger">Número de cartão já em uso.</div>
 [% CASE 'ERROR_cardnumber_length' %]
 <div class="alert alert-danger">Tamanho do número de cartão incorreto.</div>
 [% CASE 'ERROR_password_mismatch' %]
 <div class="alert alert-danger">Palavras-passe não correspondem.</div>
 [% CASE 'success_on_insert_itemtype' %]
 <div class="alert alert-success">Novo tipo de documento criado!</div>
 [% CASE 'error_on_insert_itemtype' %]
 <div class="alert alert-danger">O tipo de documento já existe!</div>
 [% CASE 'success_on_insert_circ_rule' %]
 <div class="alert alert-success">Regra de circulação criada!</div>
 [% CASE 'error_on_insert_circ_rule' %]
 <div class="alert alert-danger">Regra de circulação não criada!</div>
 [% CASE 'ERROR_password_too_short' %]
 <div class="alert alert-danger">O leitor não foi criado porque a palavra-passe é demasiado curta</div>
 [% CASE 'ERROR_password_too_weak' %]
 <div class="alert alert-danger">O leitor não foi criado porque a palavra-passe é demasiado fraca, deve conter pelo menos uma maiúscula, uma minúscula e um número </div>
 [% CASE 'ERROR_password_has_whitespaces' %]
 <div class="alert alert-danger">O leitor não foi criado porque a palavra-passe possui espaços em branco</div>
 [% CASE %][% message | html %]
 [% END %]
[% END %]
