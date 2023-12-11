[% INCLUDE 'blocking_errors.inc' %]
<div id="toolbar" class="btn-toolbar">
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Novo <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/labels/label-edit-batch.pl?op=new">Lote de etiquetas</a></li>
 <li><a href="/cgi-bin/koha/labels/label-edit-layout.pl?op=new">Esquema</a></li>
 <li><a href="/cgi-bin/koha/labels/label-edit-template.pl?op=new">Modelo de etiquetas</a></li>
 <li><a href="/cgi-bin/koha/labels/label-edit-profile.pl?op=new">Perfil da impressora</a></li>
 <li><a href="/cgi-bin/koha/labels/label-edit-range.pl">Intervalo de códigos de barras</a></li>
 </ul>
 </div>
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-edit"></i> Gerir <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=batch">Lotes de etiquetas</a></li>
 <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=layout">Esquemas</a></li>
 <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=template">Modelos de etiquetas</a></li>
 <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=profile">Perfis de impressora</a></li>
 </ul>
 </div>
</div>
