[% USE Koha %]
[% IF ( relatives_issues_count ) %]
 <table id="relatives-issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">Data de término (não formatada, escondida)</th>
 <th scope="col">Data de devolução</th>
 <th scope="col">Título</th>
 <th scope="col">Tipo de documento do registo</th>
 <th scope="col">Tipo de documento</th>
 <th scope="col">Coleção</th>
 <th scope="col">Localização</th>
 <th scope="col">Emprestado em (escondido, não formatado)</th>
 <th scope="col">Emprestado em</th>
 <th scope="col">Emprestado desde</th>
 <th scope="col">Cota</th>
 <th scope="col">Número de cópia</th>
 <th scope="col">Custo</th>
 <th scope="col">Multa</th>
 <th scope="col">Preço</th>
 <th scope="col">Leitor</th>
 </tr>
 </thead>
 </table>
[% END %]
