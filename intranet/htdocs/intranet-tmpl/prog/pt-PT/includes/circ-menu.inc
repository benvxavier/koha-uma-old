[% USE Koha %]
[% USE KohaDates %]
[% PROCESS 'member-display-address-style.inc' %]
[% IF ( patron.borrowernumber ) %]
[% SET patron_is_staff = patron.has_permission({ 'catalogue' => 1 }) %]
[% SET patron_is_superlibrarian = patron.is_superlibrarian %]
[% SET patron_type_class = 'is-not-staff' %]
[% IF ( patron_is_superlibrarian ) %]
 [% patron_type_class = 'is-staff is-superlibrarian' %]
[% ELSIF ( patron_is_staff ) %]
 [% patron_type_class = 'is-staff' %]
[% END %]
<div class="patroninfo [% patron_type_class | html %]">

[% IF ( patronimages ) %]
 <h5 class="text-center">
[% ELSE %]
 <h5>
[% END %]
 [% IF ( patron_is_staff ) %]
 <i class="fa fa-shield fa-fw" title="Staff"></i>
 [% END %]
 [% IF ( patron_is_superlibrarian ) %]
 <i class="fa fa-bolt fa-fw" title="Superbibliotecário"></i>
 [% END %]
 [% INCLUDE 'patron-title.inc' %]
 </h5>
[% IF Koha.Preference('showLastPatron') %]
 <input type="hidden" id="hiddenborrowernumber" value="[% patron.borrowernumber | html %]">
 <input type="hidden" id="hiddenborrowername" value="[% patron.surname | html %] [% patron.firstname | html %]">
 <input type="hidden" id="hiddenborrowercard" value="[% patron.cardnumber | html %]">
[% END %]

[% IF ( patronimages ) %]
 <div>
 <div class="patronimage-container">
 [% IF ( patron.image ) %]
 <img src="/cgi-bin/koha/members/patronimage.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="patronimage" alt="[% patron.firstname | html %] [% patron.surname | html %] ([% patron.cardnumber | html %])" />
 [% IF ( CAN_user_tools_batch_upload_patron_images ) %]
 <div class="patronimage-controls">
 <div class="patronimage-control"><a class="btn btn-default edit-patronimage" data-borrowernumber="[% patron.borrowernumber | uri %]" data-cardnumber="[% patron.cardnumber | html %]" href="#" title="Fotografia do leitor"><i class="fa fa-pencil"></i> Alterar</a></div>
 </div>
 [% END %]
 [% ELSE %]
 <div class="patronimage empty"></div>
 [% IF ( CAN_user_tools_batch_upload_patron_images ) %]
 <div class="patronimage-controls">
 <div class="patronimage-control"><a class="btn btn-default edit-patronimage" data-borrowernumber="[% patron.borrowernumber | uri %]" data-cardnumber="[% patron.cardnumber | html %]" href="#" title="Fotografia do leitor"><i class="fa fa-plus"></i> Adicionar</a></div>
 </div>
 [% END %]
 [% END %]
 </div>
 </div>
[% END %]

<ul class="patronbriefinfo">
 [% IF !(Koha.Preference('HidePersonalPatronDetailOnCirculation')) %]
 [% IF patron.pronouns %]
 <li class="patronpronouns">([% patron.pronouns | html %])</li>
 [% END %]

 [% PROCESS 'display-address-style' %]

 [% IF ( patron.phone || patron.mobile || patron.phonepro ) %]<li class="patronphone">
 [% IF ( patron.phone ) %]
 <a href="tel:[% patron.phone | url %]">[% patron.phone | html %]</a>
 [% ELSE %]
 [% IF ( patron.mobile ) %]
 <a href="tel:[% patron.mobile | url %]">[% patron.mobile | html %]</a>
 [% ELSE %]
 [% IF ( patron.phonepro ) %]
 <a href="tel:[% patron.phonepro | url %]">[% patron.phonepro | html %]</a>
 [% END %]
 [% END %]
 [% END %]</li>[% END %]
 [% IF ( patron.email ) %]
 <li class="email"> <a href="mailto:[% patron.email | url %]" title="[% patron.email | html %]">[% patron.email | html %]</a></li>
 [% ELSE %]
 [% IF ( patron.emailpro ) %]
 <li class="email"> <a href="mailto:[% patron.emailpro | url %]" title="[% patron.emailpro | html %]">[% patron.emailpro | html %]</a></li>
 [% END %]
 [% END %]
 [% IF ( patron.dateofbirth ) %]
 <li class="patrondateofbirth">
 <span>Data de Nascimento:</span>
 [% INCLUDE 'patron-age.inc' %]
 </li>
 [% END %]

 [% UNLESS ( patron.address or patron.address2 ) %]
 <li><span class="empty" id="noaddressstored">Nenhum endereço guardado.</span></li>
 [% END %]
 [% UNLESS ( patron.city ) %]
 <li><span class="empty" id="nocitystored">Nenhuma cidade guardada.</span></li>
 [% END %]
 [% UNLESS ( patron.phone or patron.mobile or patron.phonepro) %]
 <li> <span class="empty">Não existe telefone registado.</span></li>
 [% END %]
 [% UNLESS ( patron.email or patron.emailpro) %]
 <li> <span class="empty">Nenhum email guardado.</span></li>
 [% END %]
 [% UNLESS ( patron.dateofbirth ) %]
 <li> <span class="empty">Nenhuma data de nascimento armazenada.</span></li>
 [% END %]

 [% END %]

 [% IF Koha.Preference('ExtendedPatronAttributes') %]
 [% FOREACH extendedattribute IN patron.extended_attributes %]
 [% IF ( extendedattribute.type.display_checkout ) %] [%# FIXME We should filter in the line above %]
 [% IF ( extendedattribute.attribute ) %] [%# FIXME Why that? why not if == 0? %]
 <li class="patronattribute">
 <span class="patronattributelabel">[% extendedattribute.type.description | html %]</span>: [% extendedattribute.description | html %]
 </li>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 <li class="patroncategory">Categoria: <span class="patroncategory_description">[% patron.category.description | html %]</span> <span class="patroncategory_code">([% patron.categorycode | html %])</span></li>
 <li class="patronlibrary">Biblioteca de inscrição: [% Branches.GetName( patron.branchcode ) | html %]</li>
 <li class="patronborrowernumber">Número de leitor: [% patron.borrowernumber | html %]</li>
 <li><span class="patronupdatedon">Atualizado em [% patron.updated_on | $KohaDates with_hours => 1 %]</span></li>
 [% IF patron.account_locked %]
 [% IF patron.login_attempts < 0 %]
 <li class="blocker account_admin_locked">Esta conta foi bloqueada pela administração</li>
 [% ELSE %]
 <li class="blocker account_locked">A conta foi bloqueada</li>
 [% END %]
 [% END %]
 </ul></div>
<div id="menu">
<ul>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF ( circview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% patron.borrowernumber | uri %]">Emprestar</a></li>
 [% IF Koha.Preference('BatchCheckouts') && Koha.Preference('BatchCheckoutsValidCategories').split(',').grep('^' _ patron.categorycode _ '$').size > 0 %]
 [% IF ( batch_checkout_view ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;batch=1">Lote de empréstimo</a></li>
 [% END %]
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( detailview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% patron.borrowernumber | uri %]">Detalhes</a></li>
 [% END %]
 [% IF ( CAN_user_updatecharges_remaining_permissions ) %]
 [% IF ( finesview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[% patron.borrowernumber | uri %]">Contabilidade</a></li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions  )  %]
 [% IF Koha.Preference("RoutingSerials") %][% IF ( routinglistview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/routing-lists.pl?borrowernumber=[% patron.borrowernumber | uri %]">Listas de circulação</a></li>[% END %]
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( intranetreadinghistory ) %]
 [% IF ( readingrecordview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/readingrec.pl?borrowernumber=[% patron.borrowernumber | uri %]">Histórico do empréstimo</a></li>
 [% END %]
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( intranetreadinghistory ) %]
 [% IF ( holdshistoryview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/holdshistory.pl?borrowernumber=[% patron.borrowernumber | uri %]">Histórico de reservas</a></li>
 [% END %]
 [% END %]
 [% IF ( CAN_user_tools_view_system_logs ) %]
 [% IF ( logview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/tools/viewlog.pl?do_it=1&amp;modules=MEMBERS&amp;modules=CIRCULATION&amp;object=[% patron.borrowernumber | uri %]&amp;src=circ">Relatório de modificações</a></li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( sentnotices ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]">Avisos</a></li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF (  statisticsview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/statistics.pl?borrowernumber=[% patron.borrowernumber | uri %]">Estatísticas</a></li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( EnableBorrowerFiles ) %]
 [% IF ( borrower_files ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/files.pl?borrowernumber=[% patron.borrowernumber | uri %]">Ficheiros</a></li>
 [% END %]
 [% END %]

 [% IF CAN_user_suggestions_suggestions_manage %]
 [% IF ( suggestionsview ) %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/purchase-suggestions.pl?borrowernumber=[% patron.borrowernumber | uri %]">Sugestões de aquisição</a></li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers && useDischarge %]
 [% IF dischargeview %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/discharge.pl?borrowernumber=[% patron.borrowernumber | uri %]">Quitação</a></li>
 [% END %]
 [% IF Koha.Preference('HouseboundModule') %]
 [% IF houseboundview %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/housebound.pl?borrowernumber=[% patron.borrowernumber | uri %]">Housebound</a></li>
 [% END %]
 [% IF Koha.Preference('ILLModule') && CAN_user_ill %]
 [% IF illview %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/ill-requests.pl?borrowernumber=[% patron.borrowernumber | uri %]">Histórico de pedidos de empréstimo inter-bibliotecas</a></li>
 [% END %]
 [% IF Koha.Preference('UseRecalls') && CAN_user_recalls %]
 [% IF recallsview %]<li class="active">[% ELSE %]<li>[% END %]<a href="/cgi-bin/koha/members/recallshistory.pl?borrowernumber=[% patron.borrowernumber | uri %]">Histórico de reclamações</a></li>
 [% END %]
</ul></div>

[% IF patronimages && CAN_user_tools_batch_upload_patron_images %]
<!-- Modal -->
<div class="modal" id="patronImageEdit" tabindex="-1" role="dialog" aria-labelledby="patronImageEditLabel">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="Fechar" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 class="modal-title" id="patronImageEditLabel">Fotografia do leitor</h4>
 </div>
 <div class="modal-body">
 <div id="upload-patron-image" class="patroninfo-section">
 <h5>Carregar fotografia do leitor</h5>
 <form method="post" id="picture-upload" action="/cgi-bin/koha/tools/picture-upload.pl"
                        enctype="multipart/form-data">
 [% IF ( patron.image ) %]
 <div class="hint">
 Para atualizar a imagem para [% patron.title | html %] [% patron.firstname | html %] [% patron.surname | html %], selecione um novo ficheiro de imagem e clique em 'Carregar'. <br />Clique no botão 'Eliminar' para remover a imagem actual. </div>
 [% ELSE %]
 <div class="hint">
 [% patron.title | html %] [% patron.firstname | html %] [% patron.surname | html %] não têm uma imagem disponível. Para importar a imagem de [% patron.title | html %] [% patron.firstname | html %] [% patron.surname | html %], é necessário inserir o nome do respectivo ficheiro a carregar. </div>
 [% END %]
 <p>Apenas os formatos PNG, GIF, JPEG e XPM são suportados.</p>
 <label for="uploadfile">Seleccionar o ficheiro a carregar: </label>
 <input type="file" id="uploadfile" name="uploadfile" required="required" />
 <div class="action">
 <input type="hidden" id="csrf_token" name="csrf_token" value="[% csrf_token | html %]" />
 <input type="hidden" id="image" name="filetype" value="image" />
 <input type="hidden" id="cardnumber" name="cardnumber" value="[% patron.cardnumber | html %]" />
 <input type="hidden" id="borrowernumber" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <button type="submit" class="btn btn-default btn-xs"><i class="fa fa-upload"></i> Carregar fotografia</button>
 <input name="op" type="hidden" value="Upload" />
 [% IF ( patron.image ) %]
 <a id="delpicture"
                                    href="/cgi-bin/koha/tools/picture-upload.pl?op=Delete&amp;borrowernumber=[% patron.borrowernumber | html %]&amp;csrf_token=[% csrf_token | html %]"
                                    class="btn btn-default btn-xs delete"><i class="fa fa-trash"></i> Apagar</a>
 [% END %]
 </div>
 </form>
 </div>
 <div id="capture-patron-image" class="patroninfo-section">
 <h5>Tirar fotografia do leitor</h5>
 <form method="post" id="camera-upload" action="/cgi-bin/koha/tools/picture-upload.pl">
 <div class="btn-toolbar">
 <div class="btn-group">
 <button class="btn btn-default" id="takebutton"><i class="fa fa-camera"></i> Tirar fotografia</button>
 </div>
 <div class="btn-group">
 <button class="btn btn-default" id="retakebutton" style="display:none;"><i class="fa fa-refresh"></i> Tirar nova fotografia</button>
 </div>
 <div class="btn-group">
 <a id="downloadbutton" href="#" class="btn btn-default" style="display:none;"><i class="fa fa-download"></i> Descarregar fotografia</a>
 </div>
 <div class="btn-group">
 <button id="savebutton" type="submit" class="btn btn-default" style="display:none;"><i class="fa fa-hdd-o"></i> Carregar</button>
 </div>
 </div>
 <div id="camera">
 <video id="viewfinder">Stream de vídeo não disponível.</video>
 </div>
 <canvas id="canvas" style="display:none"></canvas>
 <div id="output" style="display:none">
 <img alt="A captura de ecrã vai aparecer nesta caixa." id="photo" style="width:100%;height:auto;">
 </div>
 <input type="hidden" name="uploadfilename" value="patron-photo.jpg" />
 <textarea id="uploadfiletext" name="uploadfiletext" style="display:none;"></textarea>
 <input type="hidden" name="csrf_token" value="[% csrf_token | html %]" />
 <input type="hidden" name="filetype" value="image" />
 <input type="hidden" name="cardnumber" value="[% patron.cardnumber | html %]" />
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input name="op" type="hidden" value="Upload" />
 </form>
 </div>
 <div class="dialog message" style="display:none" id="camera-error">
 <div>
 <span class="fa-stack fa-lg">
 <i class="fa fa-camera fa-stack-1x"></i>
 <i class="fa fa-ban fa-stack-2x text-danger"></i>
 </span>
 </div>
 <div>
 <strong>Não foi possível tirar a fotografia.</strong>
 <span id="camera-error-message"></span>
 </div>
 </div>
 </div>
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-dismiss="modal">Anular</button>
 </div>
 </div>
 </div>
</div>
[% END %]

[% END %]
