[% INCLUDE 'blocking_errors.inc' %]
<!-- acquisitions-toolbar.inc -->
<div id="toolbar" class="btn-toolbar">
 [% IF ( booksellerid ) %]
 <div class="btn-group">
 <a class="btn btn-default dropdown-toggle" data-toggle="dropdown" href="#"><i class="fa fa-plus"></i> Novo <span class="caret"></span>
 </a>
 <ul class="dropdown-menu">
 [% IF CAN_user_acquisition_order_manage && active %]
 <li><a href="/cgi-bin/koha/acqui/basketheader.pl?booksellerid=[% booksellerid | uri %]&amp;op=add_form">Cesto</a></li>
 [% END %]
 [% IF CAN_user_acquisition_contracts_manage && active %]
 <li><a href="/cgi-bin/koha/admin/aqcontract.pl?op=add_form&amp;booksellerid=[% booksellerid | uri %]">Contrato</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_vendors_manage ) %]
 <li><a href="/cgi-bin/koha/acqui/supplier.pl?op=enter">Fornecedor</a></li>
 [% END %]
 </ul>
 </div>
 [% IF ( CAN_user_acquisition_vendors_manage ) %]
 <div class="btn-group">
 <a class="btn btn-default" id="editsupplier" href="/cgi-bin/koha/acqui/supplier.pl?booksellerid=[% booksellerid | html %]&amp;op=enter"><i class="fa fa-pencil"></i> Editar fornecedor</a>
 </div>
 [% UNLESS ( basketcount OR subscriptioncount ) %]
 <div class="btn-group">
 <form action="/cgi-bin/koha/acqui/supplier.pl" method="post">
 <input type="hidden" name="op" value="delete" />
 <input type="hidden" name="booksellerid" value="[% booksellerid | html %]" />
 <button class="btn btn-default" id="deletesupplier" type="submit"><i class="fa fa-trash"></i> Eliminar fornecedor</button>
 </form>
 </div>
 [% END %]
 [% END %]
 [% IF CAN_user_acquisition_order_receive && basketcount && active %]
 <div class="btn-group"><a class="btn btn-default" id="receive" href="/cgi-bin/koha/acqui/parcels.pl?booksellerid=[% booksellerid | html %]"><i class="fa fa-inbox"></i> Receber remessas</a></div>
 [% END %]
 [% ELSE %]
 <div class="btn-group"><a class="btn btn-default" href="/cgi-bin/koha/acqui/supplier.pl?op=enter"><i class="fa fa-plus"></i> Novo fornecedor</a></div>
 [% END %]
</div>
<!-- / acquisitions-toolbar.inc -->
