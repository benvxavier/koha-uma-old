[% USE raw %]
[% IF ( PAGE_NUMBERS ) %]
 <nav aria-label="Paginação dos resultados da pesquisa" class="pagination pagination-sm noprint">
 [% IF hits_to_paginate < total %]
 <span class="h6">[% hits_to_paginate | html %] de [% total | html %] resultados carregados, redefina a pesquisa para ver outros registos</span>
 [% END %]
 <ul class="pagination">
 [% IF ( previous_page_offset.defined ) %]
 <li class="page-item">
 <a aria-label="Ir para a primeira página" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"><i class="fa fa-fw fa-angle-double-left" aria-hidden="true"></i> Primeiro</a>
 </li>
 <li class="page-item">
 <a aria-label="Ir para a página anterior" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% previous_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"> <i class="fa fa-fw fa-angle-left" aria-hidden="true"></i> Anterior</a>
 </li>
 [% END %]
 [% FOREACH PAGE_NUMBER IN PAGE_NUMBERS %]
 [% IF ( PAGE_NUMBER.highlight ) %]
 <li class="page-item disabled">
 <a aria-current="true" aria-disabled="true" aria-label="Página actual: Página [% PAGE_NUMBER.pg | html %]" class="page-link" href="#">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% ELSE %]
 <li class="page-item">
 <a aria-label="Ir para a página [% PAGE_NUMBER.pg | html %]" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% PAGE_NUMBER.offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( next_page_offset ) %]
 <li class="page-item">
 <a aria-label="Ir para a página seguinte" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% next_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">Seguinte <i class="fa fa-fw fa-angle-double-right" aria-hidden="true"></i></a>
 </li>
 <li class="page-item">
 <a aria-label="Ir para a última página" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% last_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">Último <i class="fa fa-fw fa-angle-double-right" aria-hidden="true"></i></a>
 </li>
 [% END %]
 </ul>
 </nav>
[% END %]
