<div class="actions-menu noprint">
 [% IF Koha.Preference( 'OPACHoldRequests' ) == 1 %]
 [% UNLESS ( items.norequests ) %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
 [% IF ( shelf AND op == 'view' ) # Lists view has more granular checking of hold availability %]
 [% IF ( items.allow_onshelf_holds ) %]
 <span class="actions"><a class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> Reservar</a></span>
 [% ELSE %]
 [% IF ( items.itemsissued ) %]
 <span class="actions"><a class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> Reservar</a></span>
 [% END %]
 [% END %]
 [% ELSE %]
 <span class="actions"><a class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> Reservar</a></span>
 [% END %]
 [% END # / IF opacuserlogin %]
 [% END # / UNLESS items.norequests %]
 [% END # / OPACHoldRequests %]

 [% IF Koha.Preference('UseRecalls') %]
 <span class="actions"><a class="btn btn-link btn-sm recall" href="/cgi-bin/koha/opac-recall.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark-o" aria-hidden="true"></i> Adicionar reclamação</a></span>
 [% END %]

 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) %]
 [% IF items.artreqpossible %]
 <span class="actions"><a href="/cgi-bin/koha/opac-request-article.pl?biblionumber=[% items.biblionumber | uri %]" class="btn btn-link btn-sm"><i class="fa fa-file-text" aria-hidden="true"></i> Pedido de artigo</a></span>
 [% END %]
 [% END %]

 [% IF ( TagsInputEnabled ) %]
 [% IF ( loggedinusername ) %]
 <span class="actions"><a id="tag_add[% items.biblionumber | html %]" href="#" class="tag_add btn btn-link btn-sm"><i class="fa fa-tag" aria-hidden="true"></i> Adicionar etiqueta</a></span>
 <div id="tagform[% items.biblionumber | html %]" class="tag_results_input form-inline" style="display:none;">
 <label for="newtag[% items.biblionumber | html %]">Nota tag(s), separados por vírgula:</label>
 <input type="text" name="newtag[% items.biblionumber | html %]" id="newtag[% items.biblionumber | html %]" class="form-control form-control-sm newtag" maxlength="100" />
 <input class="btn btn-sm btn-primary tagbutton" name="tagbutton" title="[% items.biblionumber | html %]" type="submit" value="Adicionar" />
 <a class="cancel_tag_add" id="cancel[% items.biblionumber | html %]" href="#">(feito)</a>
 </div>
 <span id="newtag[% items.biblionumber | html %]_status" class="tagstatus" style="display:none;">
 Estado da etiqueta aqui. </span>
 [% ELSE %]
 <span class="actions">
 <span class="login4tags">
 <a class="btn btn-link btn-sm loginModal-trigger" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-tag" aria-hidden="true"></i> Iniciar sessão para acrescentar etiquetas</a>
 </span>
 </span>
 [% END # IF loggedinusername %]
 [% END # if TagsInputEnabled %]

 [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && loggedinusername && ( Koha.Preference( 'virtualshelves' ) == 1 ) ) %]
 [% IF ( shelf AND op == 'view' ) %]
 <span class="actions"><a href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | uri %]" class="addtoshelf btn btn-link btn-sm"><i class="fa fa-list" aria-hidden="true"></i> Gravar noutra lista</a></span>
 [% IF can_remove_biblios %]
 <span class="actions"><a class="btn btn-link btn-sm removefromlist" href="/cgi-bin/koha/opac-shelves.pl?op=remove_biblios&amp;shelfnumber=[% shelf.shelfnumber | html %]&amp;biblionumber=[% items.biblionumber | html %]"><i class="fa fa-remove" aria-hidden="true"></i> Remover da lista</a></span>
 [% END %]
 [% ELSE %]
 <span class="actions"><a class="addtoshelf btn btn-link btn-sm" href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-list" aria-hidden="true"></i> Guardar nas listas</a></span>
 [% END # /IF ( shelf AND op == 'view' ) %]
 [% END # /IF Koha.Preference( 'opacuserlogin' ) %]

 [% IF Koha.Preference( 'opacbookbag' ) == 1 %]
 [% IF ( items.incart ) %]
 <span class="actions cart-actions"><a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm addtocart cart[% items.biblionumber | html %]" href="#"><i class="fa fa-shopping-cart" aria-hidden="true"></i> No seu carrinho</a> <a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm remove cartRemove cartR[% items.biblionumber | html %]" href="#">(remover)</a></span>
 [% ELSE %]
 <span class="actions cart-actions"><a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm addtocart cart cart[% items.biblionumber | html %]" href="#"><i class="fa fa-shopping-cart" aria-hidden="true"></i> Adicionar ao carrinho</a> <a style="display:none;" data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm remove cartRemove cartR[% items.biblionumber | html %]" href="#">(remover)</a></span>
 [% END %]
 [% END # / IF opacbookbag %]
</div>
