[% BLOCK asksysadmin %]<span>Por favor peça ao administrador do sistema para verificar o erro para mais detalhes.</span>[% END %]
[% BLOCK b_batch %]<span>Lote: </span>[% END %]
[% BLOCK b_patronlist %]<span>Lista de leitores: </span>[% END %]
[% BLOCK b_patronnumber %]<span>Número de leitor: </span>[% END %]
[% BLOCK b_layout %]<span>Esquema: </span>[% END %]
[% BLOCK b_template %]<span>Modelo: </span>[% END %]

[% IF ( error || error_pdferr )  %]
<div class="dialog alert">
 <p>
 <strong>AVISO:</strong>
 [% IF error_pdferr %]<span>Erro na criação do ficheiro PDF. </span>
 [% IF error_errnocards %]<span>Nenhum cartão criado (lote ou lista vazia?) </span>[% END %]
 [% IF error_errba %][% INCLUDE b_batch %]<span class="ex">[%- error_errba | html -%]</span>[% END %]
 [% IF error_errpl %][% INCLUDE b_patronlist %]<span class="ex">[%- error_errpl | html -%]</span>][% END %]
 [% IF error_errpt %][% INCLUDE b_patronnumber %]<span class="ex">[%- error_errpt | html -%]</span>[% END %]
 [% IF error_errlo %][% INCLUDE b_layout %]<span class="ex">[%- error_errlo | html -%]</span>[% END %]
 [% IF error_errtpl %][% INCLUDE b_template %]<span class="ex">[%- error_errtpl | html -%]</span>[% END %]
 [% INCLUDE asksysadmin %]
 [% END %]

 [% IF ( error == 101 ) %]
 [% IF ( card_element ) %]<span>A base de dados retornou um erro ao guardar [% card_element | html %] [% element_id | html %]. </span>
 [% ELSE %]<span>A base de dados retornou um erro na tentativa de uma operação de criação. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 102 ) %]
 [% IF ( card_element ) %]<span>A base de dados retornou um erro ao eliminar [% card_element | html %] [% element_id | html %]. </span>
 [% ELSIF ( image_ids ) %]<span>A base de dados retornou um erro ao eliminar [% image_ids | html %]. </span>
 [% ELSE %]<span>A base de dados retornou um erro na tentativa de uma operação de eliminação. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 201 ) %]
 [%IF ( element_id ) %]<span>Tentativa de execução de uma ação não suportada em [% card_element | html %] [% element_id | html %]. </span>
 [% ELSE %]<span>Tentativa de execução de uma ação não suportada. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 202 ) %]
 <span>Ocorreu um erro. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 203 ) %]
 <span>Um código não existente ou inválido foi fornecido. Por favor verifique que a biblioteca está definida. </span><a href="/cgi-bin/koha/circ/set-library.pl">Escolher a biblioteca</a>
 [% ELSIF ( error == 301 ) %]
 <span>Ocorreu um erro enquanto a imagem era carregada. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 302 ) %]
 <span>A imagem excede o limite de 2MB. Por favor redimensione a imagem e tente importar novamente. </span>
 [% ELSIF ( error == 303 ) %]
 <span>A quota de de imagens na base de dados apenas permite que tenhamos [% image_limit | html %] imagens guardadas de uma só vez. Por favor elimine uma ou mais imagens para limpar espaço de quota. </span>
 [% ELSIF ( error == 304 ) %]
 <span>Uma imagem com o nome '[% IMAGE_NAME | html %]' já existe no sistema.</span>
 [% ELSIF ( error == 401 ) %]
 <span>Ocorreu um erro e nenhum exemplar foi adicionado ao lote [% batch_id | html %]. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 402 ) %]
 <span>Nenhum item adicionado porque a biblioteca não está definida. Por favor defina a biblioteca antes de adicionar itens ao lote. </span><a href="/cgi-bin/koha/circ/set-library.pl">Escolher a biblioteca</a>
 [% ELSIF ( error == 403 ) %]
 <span>Ocorreu um erro e os exemplares não foram removidos do lote [% batch_id | html %]. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 404 ) %]
 <span>Ocorreu um erro e o lote [% batch_id | html %] não foi eliminado. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 405 ) %]
 <span>Ocorreu um erro e o lote [% batch_id | html %] não foi totalmente duplicado. </span>
 [% END %]
 </p>
</div>
[% END %]
