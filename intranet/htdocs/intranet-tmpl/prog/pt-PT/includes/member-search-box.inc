<!-- member-search-box.inc -->
[% USE Branches %]
[% USE Categories %]
[% USE Koha %]
[% PROCESS 'patronfields.inc' %]
[% IF CAN_user_borrowers_edit_borrowers %]
 [%- SET searchtype = searchtype || Koha.Preference('DefaultPatronSearchMethod') -%]
 [% IF( bs_tab_active ) %]
 <div id="patron_search" role="tabpanel" class="tab-pane active">
 [% ELSE %]
 <div id="patron_search" role="tabpanel" class="tab-pane">
 [% END %]
 <form method="post" action="/cgi-bin/koha/members/member.pl">
 <input type="hidden" name="quicksearch" value="1" />

 <div class="form-title">
 <label class="control-label">Pesquisar leitores</label>
 </div>

 <div class="form-content">
 [% IF ( Koha.Preference('RetainPatronsSearchTerms') ) %]
 <input class="head-searchbox form-control" id="searchmember" name="searchmember" placeholder="Digitar o número do cartão ou parte do nome" size="25" type="text" value="[% searchmember | html %]" />
 [% ELSE %]
 <input class="head-searchbox form-control" id="searchmember" name="searchmember" placeholder="Digitar o número do cartão ou parte do nome" size="25" type="text" />
 [% END %]

 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <div>
 [% INCLUDE patron_fields_dropdown search_box=1 %]
 </div>

 <div>
 <label for="searchtype" class="control-label">Tipo de pesquisa</label>
 <select name="searchtype" id="searchtype" class="form-control">
 [% IF searchtype == 'starts_with' %]
 <option value='starts_with' selected='selected'>Começa por</option>
 <option value='contains'>Contém</option>
 [% ELSE %]
 <option value='starts_with'>Começa por</option>
 <option value='contains' selected='selected'>Contém</option>
 [% END %]
 </select>
 </div>

 <div>
 [% SET branches = Branches.all( selected => branchcode_filter, only_from_group => 1 ) %]
 <label for="branchcode" class="control-label">Biblioteca</label>
 <select name="branchcode_filter" id="branchcode" class="form-control">
 [% IF branches.size != 1 %]
 <option value="">Qualquer</option>
 [% END %]
 [% PROCESS options_for_libraries libraries => branches %]
 </select>
 </div>

 <div>
 [% SET categories = Categories.all() %]
 <label for="categorycode" class="control-label">Categoria</label>
 <select name="categorycode_filter" id="categorycode" class="form-control">
 <option value="">Qualquer</option>
 [% FOREACH category IN categories %]
 [% IF category.categorycode == categorycode_filter %]
 <option value="[% category.categorycode | html %]" selected="selected">[% category.description | html %]</option>
 [% ELSE %]
 <option value="[% category.categorycode | html %]">[% category.description | html %]</option>
 [% END %]
 [% END %]
 </select>
 </div>
 </div>
 </form>
 </div>
[% END %]
<!-- /member-search-box.inc -->
