[%- BLOCK keyboard_shortcut_descriptions -%]
 [% SWITCH shortcut_name %]
 [%- CASE 'insert_copyright' -%]<span>Inserir símbolo de direitos de cópia (©)</span>
 [%- CASE 'insert_copyright_sound' -%]<span>Inserir símbolo de direitos de cópia (℗) (registos sonoros)</span>
 [%- CASE 'insert_delimiter' -%]<span>Inserir delimitador (‡)</span>
 [%- CASE 'subfield_help' -%]<span>Obter ajuda do subcampo</span>
 [%- CASE 'link_authorities' -%]<span>Ligar campo a autoridades</span>
 [%- CASE 'delete_field' -%]<span>Eliminar o campo corrente e copiar para a 'área de transferência'</span>
 [%- CASE 'delete_subfield' -%]<span>Eliminar o subcampo corrente e copiar para a 'área de transferência'</span>
 [%- CASE 'new_line' -%]<span>Novo campo na próxima linha</span>
 [%- CASE 'line_break' -%]<span>Inserir quebra de linha</span>
 [%- CASE 'next_position' -%]<span>Mover para a próxima posição</span>
 [%- CASE 'prev_position' -%]<span>Mover para a posição anterior</span>
 [%- CASE 'toggle_keyboard' -%]<span>Alternar Teclado</span>
 [%- CASE 'copy_line' -%]<span>Copiar o campo corrente</span>
 [%- CASE 'copy_subfield' -%]<span>Copiar o subcampo corrente</span>
 [%- CASE 'paste_line' -%]<span>Colar a selecção da 'área de transferência'</span>
 [%- CASE 'insert_line' -%]<span>Copiar o campo corrente na próxima linha</span>
 [%- END -%]
[%- END -%]
