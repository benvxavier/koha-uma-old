[% IF patron.borrowernumber %]
<table id="ill-requests-patron-[% patron.borrowernumber | html %]">
[% ELSE %]
<table id="ill-requests">
[% END %]
 <thead>
 <tr id="ill_requests_header">
 <th scope="col">Identificador do pedido</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="author"         data-related-search-on="value">Autor</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="title"         data-related-search-on="value">Título</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="article_title" data-related-search-on="value">Título do artigo</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="issue"         data-related-search-on="value">Número</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="volume"        data-related-search-on="value">Volume</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="year"          data-related-search-on="value">Ano</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="pages"         data-related-search-on="value">Páginas</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="type"          data-related-search-on="value">Tipo de pedido</th>
 <th scope="col">Identificador da encomenda</th>
 <th scope="col">Leitor</th>
 <th scope="col">Identificador do registo bibliográfico</th>
 <th scope="col">Biblioteca</th>
 <th scope="col">Estado</th>
 <th scope="col" class="placed_formatted">Colocado em</th>
 <th scope="col" class="updated_formatted">Atualizado em</th>
 <th scope="col">Respondido</th>
 <th scope="col" class="completed_formatted">Terminado em</th>
 <th scope="col">URL de acesso</th>
 <th scope="col">Custo</th>
 <th scope="col">Preço pago</th>
 <th scope="col">Comentários</th>
 <th scope="col">Notas do OPAC</th>
 <th scope="col">Notas internas</th>
 <th scope="col">Backend</th>
 <th scope="col" class="actions"></th>
 </tr>
 </thead>
 <tbody id="illview-body">
 </tbody>
</table>