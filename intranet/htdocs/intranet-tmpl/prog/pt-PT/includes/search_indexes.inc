[% USE Koha %]
[% IF refiner %]
 <select class="advsearch" name="idx" id="refiner_idx">
[% ELSE %]
 <select class="advsearch" name="idx" id="idx">
[% END %]
 [% IF ms_kw %]
 <option selected="selected" value="kw">Palavra-chave</option>
 [% ELSE %]
 <option value="kw">Palavra-chave</option>
 [% END %]
 [% IF ms_kwcommaphr %]
 <option selected="selected" value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Palavra-chave como frase</option>
 [% ELSE %]
 <option value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Palavra-chave como frase</option>
 [% END %]
 [% IF ms_au %]
 <option selected="selected" value="au">Autor</option>
 [% ELSE %]
 <option value="au">Autor</option>
 [% END %]
 [% IF ms_aucommaphr %]
 <option selected="selected" value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Autor (expressão exata)</option>
 [% ELSE %]
 <option value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Autor (expressão exata)</option>
 [% END %]
 [% IF ms_cpn %]
 <option selected="selected" value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Colectividade-autor</option>
 [% ELSE %]
 <option value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Colectividade-autor</option>
 [% END %]
 [% IF ms_cfn %]
 <option selected="selected" value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Conferência</option>
 [% ELSE %]
 <option value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Conferência</option>
 [% END %]
 [% IF ms_cpncommaphr %]
 <option selected="selected" value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Colectividade-autor (expressão exata)</option>
 [% ELSE %]
 <option value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Colectividade-autor (expressão exata)</option>
 [% END %]
 [% IF ms_cfncommaphr %]
 <option selected="selected" value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Conferência (expressão exata)</option>
 [% ELSE %]
 <option value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Conferência (expressão exata)</option>
 [% END %]
 [% IF ms_pn %]
 <option selected="selected" value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Autor-pessoa</option>
 [% ELSE %]
 <option value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Autor-pessoa</option>
 [% END %]
 [% IF ms_pncommaphr %]
 <option selected="selected" value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Nome pessoal (expressão exata)</option>
 [% ELSE %]
 <option value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Nome pessoal (expressão exata)</option>
 [% END %]
 [% IF ms_ti %]
 <option selected="selected" value="ti">Título</option>
 [% ELSE %]
 <option value="ti">Título</option>
 [% END %]
 [% IF ms_ticommaphr %]
 <option selected="selected" value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Título (expressão exata)</option>
 [% ELSE %]
 <option value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Título (expressão exata)</option>
 [% END %]
 [% IF ms_se %]
 <option selected="seleced" value="se">&nbsp;&nbsp;&nbsp;&nbsp; Título de coleção</option>
 [% ELSE %]
 <option value="se">&nbsp;&nbsp;&nbsp;&nbsp; Título de coleção</option>
 [% END %]
 [% IF ms_su %]
 <option selected="selected" value="su">Assunto</option>
 [% ELSE %]
 <option value="su">Assunto</option>
 [% END %]
 [% IF ms_sucommaphr %]
 <option selected="selected" value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Assunto (expressão exata)</option>
 [% ELSE %]
 <option value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Assunto (expressão exata)</option>
 [% END %]
 [% IF ( expanded_options ) %]
 [% IF ms_sudashbr %]
 <option selected="selected" value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Assunto e termos mais abrangentes</option>
 [% ELSE %]
 <option value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Assunto e termos mais abrangentes</option>
 [% END %]
 [% IF ms_sudashna %]
 <option selected="selected" value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Assunto e termos mais restritos</option>
 [% ELSE %]
 <option value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Assunto e termos mais restritos</option>
 [% END %]
 [% IF ms_sudashrl %]
 <option selected="selected" value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Assunto e termos relacionados</option>
 [% ELSE %]
 <option value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Assunto e termos relacionados</option>
 [% END %]
 [% END %]
 [% IF ms_bc %]
 <option selected="selected" value="bc">Código de barras</option>
 [% ELSE %]
 <option value="bc">Código de barras</option>
 [% END %]
 [% IF ms_locationcommawrdl %]
 <option selected="selected" title="Insira o valor do código da localização a pesquisar" value="location,wrdl">Localização na prateleira (código)</option>
 [% ELSE %]
 <option title="Insira o valor do código da localização a pesquisar" value="location,wrdl">Localização na prateleira (código)</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_identcommaphr %]
 <option selected="selected" value="ident,phr">Número normalizado</option>
 [% ELSE %]
 <option value="ident,phr">Número normalizado</option>
 [% END %]
 [% ELSE %]
 [% IF ms_ident %]
 <option selected="selected" value="ident">Número normalizado</option>
 [% ELSE %]
 <option value="ident">Número normalizado</option>
 [% END %]
 [% END %]
 [% IF ms_nb %]
 <option selected="selected" value="nb">&nbsp;&nbsp;&nbsp;&nbsp; ISBN</option>
 [% ELSE %]
 <option value="nb">&nbsp;&nbsp;&nbsp;&nbsp; ISBN</option>
 [% END %]
 [% IF ms_ns %]
 <option selected="selected" value="ns">&nbsp;&nbsp;&nbsp;&nbsp; ISSN</option>
 [% ELSE %]
 <option value="ns">&nbsp;&nbsp;&nbsp;&nbsp; ISSN</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_callnumcommaphr %]
 <option selected="selected" value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cota</option>
 [% ELSE %]
 <option value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cota</option>
 [% END %]
 [% ELSE %]
 [% IF ms_callnum %]
 <option selected="selected" value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Cota</option>
 [% ELSE %]
 <option value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Cota</option>
 [% END %]
 [% END %]
 [% IF ms_lncommartrn %]
 <option selected="selected" value="ln,rtrn">Idioma</option>
 [% ELSE %]
 <option value="ln,rtrn">Idioma</option>
 [% END %]
 [% IF ms_nt %]
 <option selected="selected" value="nt">Notas/comentários</option>
 [% ELSE %]
 <option value="nt">Notas/comentários</option>
 [% END %]
 [% IF (marcflavour != 'UNIMARC' ) %]
 [% IF ms_curriculum %]
 <option selected="selected" value="curriculum">Currículo</option>
 [% ELSE %]
 <option value="curriculum">Currículo</option>
 [% END %]
 [% END %]
 [% IF ms_pb %]
 <option selected="selected" value="pb">Editor</option>
 [% ELSE %]
 <option value="pb">Editor</option>
 [% END %]
 [% IF ms_pl %]
 <option selected="selected" value="pl">Local do editor</option>
 [% ELSE %]
 <option value="pl">Local do editor</option>
 [% END %]

 [%# Use non-normalized st-year instead of st-numeric, %]
 [%# since pubdate can include 'u' to signify unknown %]
 [%# dates. See "Legal Characters" at: %]
 [%# http://www.loc.gov/marc/bibliographic/bd008a.html %]
 [%# This search is also for date ranges due to the %]
 [%# special Zebra r=r CCL mapping for 'yr' %]
 [% IF ms_yrcommastdashyear %]
 <option selected="selected" value="yr,st-year">Data de publicação (aaaa-aaaa)</option>
 [% ELSE %]
 <option value="yr,st-year">Data de publicação (aaaa-aaaa)</option>
 [% END %]
 [% IF ms_acqdatecommastdashdatedashnormalized %]
 <option selected="selected" value="acqdate,st-date-normalized">Data de aquisição (aaaa-mm-dd)</option>
 [% ELSE %]
 <option value="acqdate,st-date-normalized">Data de aquisição (aaaa-mm-dd)</option>
 [% END %]
</select>
