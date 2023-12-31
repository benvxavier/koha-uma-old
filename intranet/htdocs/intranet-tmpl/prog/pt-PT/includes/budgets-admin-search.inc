[% USE Koha %]
[% USE Branches %]
<!-- budgets-admin-search.inc -->

<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="budgets_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/admin/aqbudgets.pl" method="post">
 <input type="hidden" name="budget_period_id" value="[% budget_period_id | html %]" />

 <div class="form-title">
 <label class="control-label">Pesquisar fundos</label>
 </div>

 <div class="form-content">
 <input class="query form-control" id="filter_budgetname" name="filter_budgetname" placeholder="Pesquisar fundos" type="text" value="[% filter_budgetname | html %]" />

 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <label for="filter_budgetbranch">Biblioteca</label>

 <select name="filter_budgetbranch" id="filter_budgetbranch" class="form-control">
 <option value="">Todas as bibliotecas</option>
 [% FOREACH branchloo IN Branches.all( selected => selected_branchcode ) %]
 [% IF branchloo.selected %]
 <option value="[% branchloo.branchcode | html %]" selected="selected">[% branchloo.branchname | html %]</option>
 [% ELSE %]
 <option value="[% branchloo.branchcode | html %]" >[% branchloo.branchname | html %]</option>
 [% END %]
 [% END %]
 </select>
 </div>
 </form>
 </div>

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="budgets_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#budgets_search" role="tab" title="Pesquisar fundos"><i class="fa fa-credit-card"></i> <span class="tab-title">Pesquisar fundos</span></a>
 </li>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation">
 <a aria-controls="circ_search" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Emprestar"><i class="fa fa-upload"></i> <span class="tab-title">Emprestar</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a aria-controls="catalog_search" class="keep_text" data-toggle="tab" href="#catalog_search" role="tab" title="Pesquisar no catálogo"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Pesquisar no catálogo</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- /budgets-admin-search.inc -->
