[% IF blocking_error %]
 [% SWITCH blocking_error %]
 [% CASE 'unknown_patron' %]
 <div class="dialog message">Leitor não encontrando. <a href="/cgi-bin/koha/members/members-home.pl">Voltar à pesquisa</a></div>
 [% CASE 'cannot_see_patron_infos' %]Esta conta não pode ver as informações pedidas do leitor. [% CASE 'unknown_biblio' %] <div class="dialog message">Registo bibliográfico não encontrado.</div>
 [% CASE 'unknown_item' %]
 <div class="dialog message">Exemplar não encontrado.</div>
 [% CASE 'unknown_subscription' %]
 <div class="dialog message">Assinatura não encontrada.</div>
 [% CASE 'unknown_basket' %]
 <div class="dialog message">Cesto não encontrando.</div>
 [% CASE 'unknown_vendor' %]
 <div class="dialog message">Fornecedor não encontrado.</div>
 [% CASE 'order_cannot_be_edited' %]
 <div class="dialog message">Esta encomenda não pode ser editada, o cesto está fechado ou a encomenda já foi recebida.</div>
 [% CASE 'wrong_csrf_token' %]
 <div class="dialog message">O formulário de submissão falhou (token de CSRF errado). Volte atrás, refresque a página e tente novamente.</div>
 [% CASE 'budget_is_locked' %]
 <div class="dialog message">O orçamento está bloqueado, a criação do fundo não é possível.</div>
 [% CASE 'missing_es_modules' %]
 <div class="dialog message">Os pacotes necessários à execução do Elasticsearch não se encontram instalados no seu servidor. Por favor contacte o administrador se desejar configurar o Elasticsearch</div>
 [% CASE 'insufficient_permission' %]
 <div class="dialog message">Não possui permissões necessárias para continuar.</div>
 [% CASE %][% blocking_error | html %]
 [% END %]

 [% INCLUDE 'intranet-bottom.inc' %]
 [% STOP %] [%# Will stop gracefully without processing any more of the template document.%]
[% END %]
