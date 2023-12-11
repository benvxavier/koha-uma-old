[% USE Context %]
[% SET current_article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current' ) %]
[% IF current_article_requests.count > 0 %]
 <table id="article-requests-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="article-request-record-title anti-the">Título do registo</th>
 <th class="article-request-created_on psort">Colocado em</th>
 <th class="article-request-title anti-the">Título</th>
 <th class="article-request-author">Autor</th>
 <th class="article-request-volume">Volume</th>
 <th class="article-request-issue">Número</th>
 <th class="article-request-date">Data</th>
 <th class="article-request-toc" title="Tabela de conteúdos">TOC</th>
 <th class="article-request-pages">Páginas</th>
 <th class="article-request-chapters">Capítulos</th>
 <th class="article-request-notes">Notas</th>
 <th class="article-request-format">Formato</th>
 <th class="article-request-status">Estado</th>
 <th class="article-request-branchcode">Biblioteca de levantamento</th>
 </tr>
 </thead>

 <tbody>
 [% FOREACH ar IN current_article_requests %]
 <tr>
 <td class="article-request-record-title">
 <a class="article-request-record-link-title" href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% ar.biblionumber | html %]">
 [% ar.biblio.title | html %]
 [% ar.item.enumchron | html %]
 </a>
 [% ar.biblio.author | html %]
 [% IF ar.itemnumber %] <em>(apenas [% ar.item.barcode | html %])</em>[% END %]
 </td>

 <td class="article-request-created_on">
 [% ar.created_on | $KohaDates %]
 </td>

 <td class="article-request-title">
 [% ar.title | html %]
 </td>

 <td class="article-request-author">
 [% ar.author | html %]
 </td>

 <td class="article-request-volume">
 [% ar.volume | html %]
 </td>

 <td class="article-request-issue">
 [% ar.issue | html %]
 </td>

 <td class="article-request-date">
 [% ar.date | html %]
 </td>

 <td class="article-request-toc">
 [% IF ar.toc_request %]<span>Sim</span>[% END %]
 </td>

 <td class="article-request-pages">
 [% ar.pages | html %]
 </td>

 <td class="article-request-chapters">
 [% ar.chapters | html %]
 </td>

 <td class="article-request-patron-notes">
 [% ar.patron_notes | html %]
 </td>

 <td class="article-request-format">
 [% IF ar.format == 'PHOTOCOPY' %]<span>Copiar</span>
 [% ELSIF ar.format == 'SCAN' %]<span>Leitura</span>
 [% END %]
 </td>

 <td class="article-request-status">
 [% IF ar.status == 'PENDING' %]
 <span>Pendente</span>
 [% ELSIF ar.status == 'PROCESSING' %]
 <span>A processar</span>
 [% ELSIF ar.status == 'COMPLETED' %]
 <span>Terminada</span>
 [% ELSIF ar.status == 'CANCELED' %]
 <span>Cancelado</span>
 [% END %]
 </td>

 <td class="article-request-branchcode">
 [% ar.branch.branchname | html %]
 </td>
 </tr>
 [% END %]
 </tbody>
 </table>
 [% ELSE %]
 <span>O leitor não possui nenhum pedido de artigo.</span>
 [% END %]
