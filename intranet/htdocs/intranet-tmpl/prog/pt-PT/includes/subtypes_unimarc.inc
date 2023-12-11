<p>
 <a id="show_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#"><i class="fa fa-plus-square-o"></i> Mostrar filtros de informação codificada</a>
 <a id="hide_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#" style="display:none;"><i class="fa fa-minus-square-o"></i> Esconder filtros de informação codificada</a>
</p>
<div style="display:none;" id="Coded_Fields">
<!-- SUBTYPE LIMITS -->
 <fieldset>
 <legend>Campos codificados</legend>
 <p>
 <label for="audience">Audiência: </label>
 <select id="audience" name="limit" class="subtype">
 <option value="" selected="selected" >Qualquer</option>
 <option value="ta:a">juvenil, geral</option>
 <option value="ta:b">pré-escolar (0-5)</option>
 <option value="ta:c">primária (5-8)</option>
 <option value="ta:d">infantil (9-14)</option>
 <option value="ta:e">jovem adulto</option>
 <option value="ta:k">adulto, público especializado</option>
 <option value="ta:m">adulto, Geral</option>
 <option value="ta:u">desconhecido</option>
 </select>
 </p>
 <p>
 <label for="physical_presentation">Apresentação física: </label>
 <select id="physical_presentation" name="limit" class="subtype">
 <option value="" selected="selected" >Qualquer</option>
 <option value="ff8-23:r">impressão normal</option>
 <option value="ff8-23:d">impressão larga</option>
 <option value="ff8-23:e">formato de jornal</option>
 <option value="ff8-23:f">Braille ou Moon script</option>
 <option value="ff8-23:g">micro-impressão</option>
 <option value="ff8-23:h">manuscrito</option>
 <option value="ff8-23:i">multimédia</option>
 <option value="ff8-23:j">mini-impressão</option>
 <option value="ff8-23:s">recurso electrónico</option>
 <option value="ff8-23:t">microforma</option>
 <option value="ff8-23:z">outra forma de material</option>
 </select>
 </p>
 <p>
 <label for="literary_genre">Forma literária: </label>
 <select id="literary_genre" name="limit" class="subtype">
 <option value="" selected="selected" >Qualquer</option>
 <option value="lf:a">ficção</option>
 <option value="lf:b">drama</option>
 <option value="lf:c">ensaios</option>
 <option value="lf:d">humor, sátira</option>
 <option value="lf:e">cartas</option>
 <option value="lf:f">contos</option>
 <option value="lf:g">poesia</option>
 <option value="lf:h">discursos, oratória</option>
 <option value="lf:i">libreto</option>
 <option value="lf:y">texto não literário</option>
 <option value="lf:z">formas múltiplas ou outras formas literárias</option>
 </select>
 </p>
 <p>
 <label for="biography">Biografia: </label>
 <select id="biography" name="limit" class="subtype">
 <option value="">Qualquer</option>
 <option value="bio:y">texto não biográfico</option>
 <option value="bio:a">autobiografia</option>
 <option value="bio:b">biografia individual</option>
 <option value="bio:c">biografia colectiva</option>
 <option value="bio:d">contém informação biográfica</option>
 </select>
 </p>
 <p>
 <label for="illustration">Ilustração: </label>
 <select id="illustration" name="limit" class="subtype">
 <option value="">Qualquer</option>
 <option value="ff8-18-21:a">ilustrações</option>
 <option value="ff8-18-21:b">mapas</option>
 <option value="ff8-18-21:c">retratos</option>
 <option value="ff8-18-21:d">gráficos</option>
 <option value="ff8-18-21:e">planos</option>
 <option value="ff8-18-21:f">placas</option>
 <option value="ff8-18-21:g">música</option>
 <option value="ff8-18-21:h">fac-símiles</option>
 <option value="ff8-18-21:i">brasões de armas</option>
 <option value="ff8-18-21:j">tabelas genealógicas</option>
 <option value="ff8-18-21:k">formulários</option>
 <option value="ff8-18-21:l">amostras</option>
 <option value="ff8-18-21:m">registos sonoros</option>
 <option value="ff8-18-21:n">transparências</option>
 <option value="ff8-18-21:o">iluminuras</option>
 <option value="ff8-18-21:y">sem ilustrações</option>
 </select>
 </p>
 <p>
 <label for="content">Conteúdo: </label>
 <select id="content" name="limit" class="subtype">
 <option value="" >Qualquer</option>
 <option value="ctype:a" >bibliografia</option>
 <option value="ctype:b" >catálogo</option>
 <option value="ctype:c" >índice</option>
 <option value="ctype:d" >resumo</option>
 <option value="ctype:e" >dicionário</option>
 <option value="ctype:f" >enciclopédia</option>
 <option value="ctype:g" >directoria</option>
 <option value="ctype:h" >descrição do projecto</option>
 <option value="ctype:i" >estatísticas</option>
 <option value="ctype:j" >livro de texto programado</option>
 <option value="ctype:k" >patente</option>
 <option value="ctype:l" >norma</option>
 <option value="ctype:m" >dissertação ou tese</option>
 <option value="ctype:n" >leis e legislação</option>
 <option value="ctype:o" >tabela numérica</option>
 <option value="ctype:p" >relatório técnico</option>
 <option value="ctype:q" >questionário para exame</option>
 <option value="ctype:r" >ensaios literários/revisões</option>
 <option value="ctype:s" >tratados</option>
 <option value="ctype:t" >banda desenhada</option>
 <option value="ctype:v" >dissertação ou tese (revista)</option>
 <option value="ctype:w" >texto religioso</option>
 <option value="ctype:z" >outro</option>
 </select>
 </p>
 <p>
 <label for="video_types">Tipos de vídeo: </label>
 <select id="video_types" name="limit" class="subtype">
 <option value="">Qualquer</option>
 <option value="Video-mt:a">imagem em movimento</option>
 <option value="Video-mt:b">projecção visual</option>
 <option value="Video-mt:c">registo vídeo</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>Periódicos</legend>
 <p>
 <label for="serial_type">Tipo de periódico: </label>
 <select id="serial_type" name="limit" class="subtype">
 <option value="">Qualquer tipo</option>
 <option value="ff8-21:a">Periódico</option>
 <option value="ff8-21:b">Coleção monográfica</option>
 <option value="ff8-21:c">Jornal</option>
 <option value="ff8-21:e">Folha-solta em atualização</option>
 <option value="ff8-21:f">Base de dados</option>
 <option value="ff8-21:g">Website em atualização</option>
 <option value="ff8-21:z">Outros</option>
 </select>
 </p>
 <p>
 <label for="periodicity">Periodicidade: </label>
 <select id="periodicity" name="limit" class="subtype">
 <option value="">Qualquer</option>
 <option value="ff8-18:a">Diário</option>
 <option value="ff8-18:b">Bisemanal</option>
 <option value="ff8-18:c">Semanal</option>
 <option value="ff8-18:d">Bisemanal</option>
 <option value="ff8-18:e">Bimensal</option>
 <option value="ff8-18:f">Mensal</option>
 <option value="ff8-18:g">Bimensal</option>
 <option value="ff8-18:h">Trimestrais</option>
 <option value="ff8-18:i">Três vezes por ano</option>
 <option value="ff8-18:j">Semestral</option>
 <option value="ff8-18:k">Anual</option>
 <option value="ff8-18:l">Bienal</option>
 <option value="ff8-18:m">Trienal</option>
 <option value="ff8-18:n">Três vezes por semana</option>
 <option value="ff8-18:o">Três vezes por mês</option>
 <option value="ff8-18:y">Sem periodicidade</option>
 <option value="ff8-18:u">Desconhecido</option>
 <option value="ff8-18:z">Outros</option>
 </select>
 </p>
 <p>
 <label for="regularity">Regularidade: </label>
 <select id="regularity" name="limit" class="subtype">
 <option value="">Qualquer regularidade</option>
 <option value="ff8-19:a">regular</option>
 <option value="ff8-19:b">irregular normalizado</option>
 <option value="ff8-19:y">irregular</option>
 <option value="ff8-19:u">desconhecido</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>Imagem</legend>
 <p>
 <select name="limit" class="subtype">
 <option value="">Qualquer</option>
 <option value="Graphics-type:a">colagem</option>
 <option value="Graphics-type:b">desenho</option>
 <option value="Graphics-type:c">pintura</option>
 <option value="Graphics-type:d">reprodução fotomecânica</option>
 <option value="Graphics-type:e">negativo fotográfico</option>
 <option value="Graphics-type:f">fotocópia</option>
 <option value="Graphics-type:h">imagem</option>
 <option value="Graphics-type:i">impressão</option>
 <option value="Graphics-type:k">desenho técnico</option>
 <option value="Graphics-type:z">outro material gráfico não-projectável</option>
 </select>
 <select name="limit" class="subtype">
 <option value="">Qualquer</option>
 <option value="Graphics-support:a">tela</option>
 <option value="Graphics-support:b">cartolina</option>
 <option value="Graphics-support:c">cartão/placa de ilustração</option>
 <option value="Graphics-support:d">vidro</option>
 <option value="Graphics-support:j">gesso</option>
 <option value="Graphics-support:k">cartão prensado</option>
 <option value="Graphics-support:l">porcelana</option>
 <option value="Graphics-support:m">pedra</option>
 <option value="Graphics-support:n">madeira</option>
 <option value="Graphics-support:v">coleção mista</option>
 <option value="Graphics-support:e">sintéticos</option>
 <option value="Graphics-support:f">película</option>
 <option value="Graphics-support:g">têxtil</option>
 <option value="Graphics-support:h">metal</option>
 <option value="Graphics-support:i">papel</option>
 <option value="Graphics-support:z">outros</option>
 <option value="Graphics-support:u">desconhecido</option>
 </select>
 </p>
</fieldset>
</div>
