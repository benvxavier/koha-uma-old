<option value="relevance">Relevância</option>

<optgroup label="Popularidade">
 
 [% IF ( sort_by == "popularity_dsc" ) %]
<option value="popularity_dsc" selected="selected">Popularidade (mais para menos)</option>
[% ELSE %]
 <option value="popularity_dsc">Popularidade (mais para menos)</option>
 [% END %]
[% IF ( sort_by == "popularity_asc" ) %]
<option value="popularity_asc" selected="selected">Popularidade (menos para mais)</option>
[% ELSE %]
 <option value="popularity_asc">Popularidade (menos para mais)</option>
 [% END %]

</optgroup>

<optgroup label="Autor">
 
 [% IF ( sort_by == "author_az" || sort_by == "author_asc" ) %]
<option value="author_az" selected="selected">Autor (A-Z)</option> 
[% ELSE %]
<option value="author_az">Autor (A-Z)</option>
 [% END %]
[% IF ( sort_by == "author_za" || sort_by == "author_dsc" ) %]
<option value="author_za" selected="selected">Autor (Z-A)</option>
[% ELSE %]
<option value="author_za">Autor (Z-A)</option>
 [% END %]

</optgroup>

<optgroup label="Cota">
 
 [% IF ( sort_by == "call_number_asc" ) %]
<option value="call_number_asc" selected="selected">Cota (0-9 a A-Z)</option>
[% ELSE %]
 <option value="call_number_asc">Cota (0-9 a A-Z)</option>
[% END %]

[% IF ( sort_by == "call_number_dsc" ) %]
<option value="call_number_dsc" selected="selected">Cota (Z-A a 9-0)</option>
[% ELSE %]
 <option value="call_number_dsc">Cota (Z-A a 9-0)</option>
[% END %]

</optgroup>

<optgroup label="Datas">
 [% IF ( sort_by == "pubdate_dsc" ) %]
<option value="pubdate_dsc" selected="selected" >Data de publicação: do mais recente para o mais antigo</option>
 [% ELSE %]
<option value="pubdate_dsc">Data de publicação: do mais recente para o mais antigo</option>
[% END %]

[% IF ( sort_by == "pubdate_asc" ) %]
<option value="pubdate_asc" selected="selected" >Data de publicação: do mais antigo para o mais recente</option>
[% ELSE %]
<option value="pubdate_asc">Data de publicação: do mais antigo para o mais recente</option>
[% END %]

[% IF ( sort_by == "acqdate_dsc" ) %]
<option value="acqdate_dsc" selected="selected">Data de aquisição: do mais recente ao mais antigo</option>
[% ELSE %]
<option value="acqdate_dsc">Data de aquisição: do mais recente ao mais antigo</option>
 [% END %]

 [% IF ( sort_by == "acqdate_asc" ) %]
<option value="acqdate_asc" selected="selected">Data de aquisição: do mais antigo ao mais recente</option>
[% ELSE %]
<option value="acqdate_asc">Data de aquisição: do mais antigo ao mais recente</option>
 [% END %]
</optgroup>

<optgroup label="Título">
 [% IF ( sort_by == "title_az" || sort_by == "title_asc" ) %]
<option value="title_az" selected="selected">Título (A-Z)</option>
 [% ELSE %]
<option value="title_az">Título (A-Z)</option>
 [% END %]
 [% IF ( sort_by == "title_za" || sort_by == "title_dsc" ) %]
<option value="title_za" selected="selected">Título (Z-A)</option> 
 [% ELSE %]
<option value="title_za">Título (Z-A)</option>
[% END %]
</optgroup>
