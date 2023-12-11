[% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <!-- patron-search-box.inc -->
 [% IF( bs_tab_active ) %]
 <div id="circ_search" role="tabpanel" class="tab-pane active">
 [% ELSE %]
 <div id="circ_search" role="tabpanel" class="tab-pane">
 [% END %]
 <form action="/cgi-bin/koha/circ/circulation.pl" id="patronsearch" method="post">
 <div class="form-title">
 <label class="control-label" for="findborrower">Emprestar</label>
 </div>

 <div class="form-content">
 <input autocomplete="off" class="head-searchbox form-control" id="findborrower" name="findborrower" placeholder="Digitar o número do cartão ou parte do nome" size="40" type="text" />

 [% IF ( stickyduedate ) %]
 <input type="hidden" name="duedatespec" value="[% duedatespec | html %]" />
 <input type="hidden" name="stickyduedate" value="[% stickyduedate | html %]" />
 [% END %]
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>
 <!-- /patron-search-box.inc -->
[% END %]
