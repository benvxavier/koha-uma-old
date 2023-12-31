<!-- adv-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' bs_tab_active= 1 %]
 [% INCLUDE 'checkin-search-box.inc' %]
 [% INCLUDE 'renew-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_borrowers_edit_borrowers ) %]
 [% INCLUDE 'member-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation" class="active">
 <a aria-controls="circ_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Emprestar"><i class="fa fa-upload"></i> <span class="tab-title">Emprestar</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="checkin_search" class="keep_text" data-toggle="tab" href="#checkin_search" role="tab" title="Devolver"><i class="fa fa-download"></i> <span class="tab-title">Devolver</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="renew_search" class="keep_text" data-toggle="tab" href="#renew_search" role="tab" title="Renovar"><i class="fa fa-retweet"></i> <span class="tab-title">Renovar</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_borrowers_edit_borrowers ) %]
 <li role="presentation">
 <a aria-controls="patron_search" class="keep_text" data-toggle="tab" href="#patron_search" role="tab" title="Pesquisar leitores"><i class="fa fa-fw fa-id-card-o"></i> <span class="tab-title">Pesquisar leitores</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- adv-search.inc -->
