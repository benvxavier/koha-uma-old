[%- BLOCK subtype_dropdowns -%]
 <select name="limit" class="subtype">
 [% IF ( limits.aud.size ) %]
 <option value="" class="menuheader">Qualquer audiência</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Qualquer audiência</option>
 [% END %]
 [% IF (limits.aud.0 == 'a' ) %]
 <option selected="selected" value="aud:a">Pré-escolar</option>
 [% ELSE %]
 <option value="aud:a">Pré-escolar</option>
 [% END %]
 [% IF (limits.aud.0 == 'b' ) %]
 <option value="aud:b" selected="selected">Primário</option>
 [% ELSE %]
 <option value="aud:b">Primário</option>
 [% END %]
 [% IF (limits.aud.0 == 'c' ) %]
 <option value="aud:c" selected="selected">Pré-adolescente</option>
 [% ELSE %]
 <option value="aud:c">Pré-adolescente</option>
 [% END %]
 [% IF (limits.aud.0 == 'd' ) %]
 <option value="aud:d" selected="selected">Adolescente</option>
 [% ELSE %]
 <option value="aud:d">Adolescente</option>
 [% END %]
 [% IF (limits.aud.0 == 'e' ) %]
 <option value="aud:e" selected="selected">Adulto</option>
 [% ELSE %]
 <option value="aud:e">Adulto</option>
 [% END %]
 [% IF (limits.aud.0 == 'f' ) %]
 <option value="aud:f" selected="selected">Especializado</option>
 [% ELSE %]
 <option value="aud:f">Especializado</option>
 [% END %]
 [% IF (limits.aud.0 == 'g' ) %]
 <option value="aud:g" selected="selected">Geral</option>
 [% ELSE %]
 <option value="aud:g">Geral</option>
 [% END %]
 [% IF (limits.aud.0 == 'j' ) %]
 <option value="aud:j" selected="selected">Juvenil</option>
 [% ELSE %]
 <option value="aud:j">Juvenil</option>
 [% END %]
 [% limits.delete( 'aud' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.fic.size OR limits.bio.size OR limits.mus.size ) %]
 <option value="" class="menuheader">Qualquer conteúdo</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Qualquer conteúdo</option>
 [% END %]
 [% IF (limits.fic.0 == '1' ) %]
 <option value="fic:1" selected="selected" >Ficção</option>
 [% ELSE %]
 <option value="fic:1" >Ficção</option>
 [% END %]
 [% IF (limits.fic.0 == '0' ) %]
 <option value="fic:0" selected="selected" >Não ficção</option>
 [% ELSE %]
 <option value="fic:0" >Não ficção</option>
 [% END %]
 [% IF (limits.bio.0 == 'b' ) %]
 <option value="bio:b" selected="selected" >Biografia</option>
 [% ELSE %]
 <option value="bio:b" >Biografia</option>
 [% END %]
 [% IF (limits.mus.0 == 'j' ) %]
 <option value="mus:j" selected="selected" >Recordação musical</option>
 [% ELSE %]
 <option value="mus:j" >Recordação musical</option>
 [% END %]
 [% IF (limits.mus.0 == 'i' ) %]
 <option value="mus:i" selected="selected" >Gravação não-musical</option>
 [% ELSE %]
 <option value="mus:i" >Gravação não-musical</option>
 [% END %]
 [% limits.delete( 'fic' ) %]
 [% limits.delete( 'bio' ) %]
 [% limits.delete( 'mus' ) %]
 </select>

 [% SET lformat = 'l-format' %]
 <select name="limit" class="subtype">
 [% IF ( limits.$lformat.size ) %]
 <option value="" class="menuheader">Qualquer formato</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Qualquer formato</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ta' ) %]
 <option value="l-format:ta" selected="selected" >Impressão normal</option>
 [% ELSE %]
 <option value="l-format:ta" >Impressão normal</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tb' ) %]
 <option value="l-format:tb" selected="selected" >Impressão grande</option>
 [% ELSE %]
 <option value="l-format:tb" >Impressão grande</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tc or fb' ) %]
 <option value="l-format:tc or fb" selected="selected" >Braille</option>
 [% ELSE %]
 <option value="l-format:tc or fb" >Braille</option>
 [% END %]
 <option value="" >-----------</option>
 [% IF (limits.$lformat.0 == 'sd' ) %]
 <option value="l-format:sd" selected="selected" >CD áudio</option>
 [% ELSE %]
 <option value="l-format:sd" >CD áudio</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ss' ) %]
 <option value="l-format:ss" selected="selected" >Gravação em cassete</option>
 [% ELSE %]
 <option value="l-format:ss" >Gravação em cassete</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vf' ) %]
 <option value="l-format:vf" selected="selected" >VHS Fita/ Vídeo-cassete</option>
 [% ELSE %]
 <option value="l-format:vf" >VHS Fita/ Vídeo-cassete</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vd' ) %]
 <option value="l-format:vd" selected="selected" >DVD Video / Videodisco</option>
 [% ELSE %]
 <option value="l-format:vd" >DVD Video / Videodisco</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'co' ) %]
 <option value="l-format:co" selected="selected" >Programas em CD</option>
 [% ELSE %]
 <option value="l-format:co" >Programas em CD</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'cr' ) %]
 <option value="l-format:cr" selected="selected" >Site Web</option>
 [% ELSE %]
 <option value="l-format:cr" >Site Web</option>
 [% END %]
 [% limits.delete( 'l-format' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.ctype.size ) %]
 <option value="" >Outros tipos de conteúdo</option>
 [% ELSE %]
 <option value="" selected="selected" >Outros tipos de conteúdo</option>
 [% END %]
 [% IF (limits.ctype.0 == 'a' ) %]
 <option value="ctype:a" selected="selected" >Resumos / sumários</option>
 [% ELSE %]
 <option value="ctype:a" >Resumos / sumários</option>
 [% END %]
 [% IF (limits.ctype.0 == 'b' ) %]
 <option value="ctype:b" selected="selected" >Bibliografias</option>
 [% ELSE %]
 <option value="ctype:b" >Bibliografias</option>
 [% END %]
 [% IF (limits.ctype.0 == 'c' ) %]
 <option value="ctype:c" selected="selected" >Catálogos</option>
 [% ELSE %]
 <option value="ctype:c" >Catálogos</option>
 [% END %]
 [% IF (limits.ctype.0 == 'e' ) %]
 <option value="ctype:e" selected="selected" >Enciclopédias </option>
 [% ELSE %]
 <option value="ctype:e" >Enciclopédias </option>
 [% END %]
 [% IF (limits.ctype.0 == 'f' ) %]
 <option value="ctype:f" selected="selected" >Manuais</option>
 [% ELSE %]
 <option value="ctype:f" >Manuais</option>
 [% END %]
 [% IF (limits.ctype.0 == 'g' ) %]
 <option value="ctype:g" selected="selected" >Artigos Legais</option>
 [% ELSE %]
 <option value="ctype:g" >Artigos Legais</option>
 [% END %]
 [% IF (limits.ctype.0 == 'i' ) %]
 <option value="ctype:i" selected="selected" >Índices</option>
 [% ELSE %]
 <option value="ctype:i" >Índices</option>
 [% END %]
 [% IF (limits.ctype.0 == 'j' ) %]
 <option value="ctype:j" selected="selected" >Patente</option>
 [% ELSE %]
 <option value="ctype:j" >Patente</option>
 [% END %]
 [% IF (limits.ctype.0 == 'k' ) %]
 <option value="ctype:k" selected="selected" >Discografias</option>
 [% ELSE %]
 <option value="ctype:k" >Discografias</option>
 [% END %]
 [% IF (limits.ctype.0 == 'l' ) %]
 <option value="ctype:l" selected="selected" >Legislação</option>
 [% ELSE %]
 <option value="ctype:l" >Legislação</option>
 [% END %]
 [% IF (limits.ctype.0 == 'm' ) %]
 <option value="ctype:m" selected="selected" >Teses</option>
 [% ELSE %]
 <option value="ctype:m" >Teses</option>
 [% END %]
 [% IF (limits.ctype.0 == 'n' ) %]
 <option value="ctype:n" selected="selected" >Ensaios</option>
 [% ELSE %]
 <option value="ctype:n" >Ensaios</option>
 [% END %]
 [% IF (limits.ctype.0 == 'o' ) %]
 <option value="ctype:o" selected="selected" >Revisões</option>
 [% ELSE %]
 <option value="ctype:o" >Revisões</option>
 [% END %]
 [% IF (limits.ctype.0 == 'p' ) %]
 <option value="ctype:p" selected="selected" >Textos programados</option>
 [% ELSE %]
 <option value="ctype:p" >Textos programados</option>
 [% END %]
 [% IF (limits.ctype.0 == 'q' ) %]
 <option value="ctype:q" selected="selected" >Filmografias</option>
 [% ELSE %]
 <option value="ctype:q" >Filmografias</option>
 [% END %]
 [% IF (limits.ctype.0 == 'r' ) %]
 <option value="ctype:r" selected="selected" >Directorias</option>
 [% ELSE %]
 <option value="ctype:r" >Directorias</option>
 [% END %]
 [% IF (limits.ctype.0 == 's' ) %]
 <option value="ctype:s" selected="selected" >Estatísticas</option>
 [% ELSE %]
 <option value="ctype:s" >Estatísticas</option>
 [% END %]
 [% IF (limits.ctype.0 == 't' ) %]
 <option value="ctype:t" selected="selected" >Relatórios técnicos</option>
 [% ELSE %]
 <option value="ctype:t" >Relatórios técnicos</option>
 [% END %]
 [% IF (limits.ctype.0 == 'v' ) %]
 <option value="ctype:v" selected="selected" >Casos legais e notas dos casos</option>
 [% ELSE %]
 <option value="ctype:v" >Casos legais e notas dos casos</option>
 [% END %]
 [% IF (limits.ctype.0 == 'w' ) %]
 <option value="ctype:w" selected="selected" >Relatórios legais e resumos</option>
 [% ELSE %]
 <option value="ctype:w" >Relatórios legais e resumos</option>
 [% END %]
 [% IF (limits.ctype.0 == 'z' ) %]
 <option value="ctype:z" selected="selected" >Tratados </option>
 [% ELSE %]
 <option value="ctype:z" >Tratados </option>
 [% END %]
 [% limits.delete( 'ctype' ) %]
 </select>
[%- END -%]
