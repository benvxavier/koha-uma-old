[% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <!-- checkin-search-box.inc -->
 [% IF( bs_tab_active ) %]
 <div id="checkin_search" role="tabpanel" class="tab-pane active">
 [% ELSE %]
 <div id="checkin_search" role="tabpanel" class="tab-pane">
 [% END %]
 <form method="post" action="/cgi-bin/koha/circ/returns.pl" autocomplete="off">
 <div class="form-title">
 <label class="control-label">Devolver</label>
 </div>

 <div class="form-content">
 <input accesskey="r" class="head-searchbox form-control" id="ret_barcode" name="barcode" placeholder="Digitar o código barras a devolver" size="40" type="text" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>
 <!-- /checkin-search-box.inc -->
[% END %]
