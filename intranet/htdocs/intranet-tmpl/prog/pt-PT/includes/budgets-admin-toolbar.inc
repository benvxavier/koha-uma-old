[% INCLUDE 'blocking_errors.inc' %]
<div id="toolbar" class="btn-toolbar">
 [% IF ( budget_period_id ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Novo <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form">Novo orçamento</a></li>
 [% IF ( budget_period_locked || !CAN_user_acquisition_budget_add_del ) %]
 <li class="disabled">
 <a data-placement="left" data-toggle="tooltip" href="#" title="O orçamento está bloqueado">Novo fundo para [% budget_period_description | html %]</a>
 </li>
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/aqbudgets.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">Novo fundo para [% budget_period_description | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-pencil"></i> Alterar <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">Editar orçamento [% budget_period_description | html %]</a></li>
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=duplicate_form&amp;budget_period_id=[% budget_period_id | uri %]">Duplicar orçamento [% budget_period_description | html %]</a></li>
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-pencil"></i> Planeamento <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=MONTHS">Planear por meses</a></li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=BRANCHES">Planear por bibliotecas</a></li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=ITEMTYPES">Planear por tipo de documento</a></li>
 [% FOREACH auth_cats_loo IN auth_cats_loop %]
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=[% auth_cats_loo | uri %]">Planear por [% auth_cats_loo | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 [% ELSE %]
 <div class="btn-group"><a class="btn btn-default" id="newrootbudget" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form"><i class="fa fa-plus"></i> Novo orçamento</a></div>
 [% END %]

</div>
