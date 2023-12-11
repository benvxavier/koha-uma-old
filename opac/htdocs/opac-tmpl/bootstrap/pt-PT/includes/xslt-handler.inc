[% SWITCH code %]
 [% CASE 'XSLTH_ERR_NO_FILE' %]
 <span>Não foi passado um ficheiro XSLT.</span>
 [% CASE 'XSLTH_ERR_FILE_NOT_FOUND' %]
 <span>Ficheiro XSLT não encontrado.</span>
 [% CASE 'XSLTH_ERR_LOADING' %]
 <span>Erro ao carregar a folha de estilo.</span>
 [% CASE 'XSLTH_ERR_PARSING_CODE' %]
 <span>Erro ao analisar a folha de estilo.</span>
 [% CASE 'XSLTH_ERR_PARSING_DATA' %]
 <span>Erro ao analisar a entrada.</span>
 [% CASE 'XSLTH_ERR_TRANSFORMING' %]
 <span>Erro ao transformar a entrada.</span>
 [% CASE 'XSLTH_NO_STRING_PASSED' %]
 <span>Nenhuma frase para transformar.</span>
[% END %]
