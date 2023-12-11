[%- BLOCK patron_fields -%]
 [%- SWITCH name -%]
 [%- CASE standard -%]<span>Omissão</span>
 [%- CASE full_address -%]<span>Endereço completo</span>
 [%- CASE all_emails -%]<span>Todos os emails</span>
 [%- CASE all_phones -%]<span>Todos os telefones</span>
 [%- CASE 'borrowernumber' -%]<span>Número de leitor</span>
 [%- CASE 'cardnumber' -%]<span>Número de cartão</span>
 [%- CASE 'surname' -%]<span>Apelido</span>
 [%- CASE 'firstname' -%]<span>Primeiro nome</span>
 [%- CASE 'middle_name' -%]<span>Nome do meio</span>
 [%- CASE 'title' -%]<span>Saudação</span>
 [%- CASE 'othernames' -%]<span>Outro nome</span>
 [%- CASE 'initials' -%]<span>Iniciais</span>
 [%- CASE 'pronouns' -%]<span>Pronomes</span>
 [%- CASE 'streetnumber' -%]<span>Número de rua</span>
 [%- CASE 'streettype' -%]<span>Tipo de rua</span>
 [%- CASE 'address' -%]<span>Morada</span>
 [%- CASE 'address2' -%]<span>Morada 2</span>
 [%- CASE 'city' -%]<span>Cidade</span>
 [%- CASE 'state' -%]<span>Estado</span>
 [%- CASE 'zipcode' -%]<span>Código postal</span>
 [%- CASE 'country' -%]<span>País</span>
 [%- CASE 'email' -%]<span>Email primário</span>
 [%- CASE 'phone' -%]<span>Telefone primário</span>
 [%- CASE 'mobile' -%]<span>Telemóvel</span>
 [%- CASE 'fax' -%]<span>Fax</span>
 [%- CASE 'emailpro' -%]<span>Email secundário</span>
 [%- CASE 'phonepro' -%]<span>Telefone secundário</span>
 [%- CASE 'B_streetnumber' -%]<span>Número de polícia alternativo</span>
 [%- CASE 'B_streettype' -%]<span>Tipo de rua alternativo</span>
 [%- CASE 'B_address' -%]<span>Endereço alternativo</span>
 [%- CASE 'B_address2' -%]<span>Linha 2 do endereço alternativo</span>
 [%- CASE 'B_city' -%]<span>Cidade alternativa</span>
 [%- CASE 'B_state' -%]<span>Estado alternativo</span>
 [%- CASE 'B_zipcode' -%]<span>Código postal alternativo</span>
 [%- CASE 'B_country' -%]<span>País alternativo</span>
 [%- CASE 'B_email' -%]<span>E-mail alternativo</span>
 [%- CASE 'B_phone' -%]<span>Telefone alternativo</span>
 [%- CASE 'dateofbirth' -%]<span>Data de nascimento</span>
 [%- CASE 'branchcode' -%]<span>Biblioteca (código)</span>
 [%- CASE 'categorycode' -%]<span>Categoria (código)</span>
 [%- CASE 'dateenrolled' -%]<span>Data de inscrição</span>
 [%- CASE 'dateexpiry' -%]<span>Data de término</span>
 [%- CASE 'gonenoaddress' -%]<span>Perdido sem endereço</span>
 [%- CASE 'lost' -%]<span>Cartão perdido</span>
 [%- CASE 'debarred' -%]<span>Restringido</span>
 [%- CASE 'debarredcomment' -%]<span>Razão da restrição</span>
 [%- CASE 'contactname' -%]<span>Apelido do fiador</span>
 [%- CASE 'contactfirstname' -%]<span>Primeiro nome do fiador</span>
 [%- CASE 'contacttitle' -%]<span>Título do fiado</span>
 [%- CASE 'guarantorid' -%]<span>Fiador</span>
 [%- CASE 'borrowernotes' -%]<span>Notas de empréstimo</span>
 [%- CASE 'relationship' -%]<span>Relação do fiador</span>
 [%- CASE 'sex' -%]<span>Sexo</span>
 [%- CASE 'flags' -%]<span>Permissões (código)</span>
 [%- CASE 'userid' -%]<span>Nome do utilizador</span>
 [%- CASE 'opacnote' -%]<span>Nota pública</span>
 [%- CASE 'contactnote' -%]<span>Nota de contacto</span>
 [%- CASE 'sort1' -%]<span>Critério 1</span>
 [%- CASE 'sort2' -%]<span>Critério 2</span>
 [%- CASE 'altcontactfirstname' -%]<span>Contacto alternativo: Primeiro nome</span>
 [%- CASE 'altcontactsurname' -%]<span>Contacto alternativo: Apelido</span>
 [%- CASE 'altcontactaddress1' -%]<span>Contacto alternativo: Morada</span>
 [%- CASE 'altcontactaddress2' -%]<span>Contacto alternativo: Morada 2</span>
 [%- CASE 'altcontactaddress3' -%]<span>Contacto alternativo: Cidade</span>
 [%- CASE 'altcontactstate' -%]<span>Contacto alternativo: Estado</span>
 [%- CASE 'altcontactzipcode' -%]<span>Código postal do contacto alternativo</span>
 [%- CASE 'altcontactcountry' -%]<span>Contacto alternativo: País</span>
 [%- CASE 'altcontactphone' -%]<span>Contacto alternativo: Telefone</span>
 [%- CASE 'smsalertnumber' -%]<span>Número para SMS</span>
 [%- CASE 'sms_provider_id' -%]<span>Operador SMS</span>
 [%- CASE 'privacy' -%]<span>Privacidade (código)</span>
 [%- CASE 'privacy_guarantor_checkouts' -%]<span>O fiador pode ver os empréstimos</span>
 [%- CASE 'updated_on' -%]<span>Última atualização</span>
 [%- CASE 'lastseen' -%]<span>Último acesso</span>
 [%- CASE 'checkprevcheckout' -%]<span>Verificar empréstimos anteriores</span>
 [%- CASE DEFAULT -%]
 [%- END -%]
[%- END -%]
[%- BLOCK patron_fields_dropdown -%]
 [% IF search_box %]
 <label for="searchfieldstype" class="control-label">Campos de pesquisa:</label>
 <select name="searchfieldstype" id="searchfieldstype" class="form-control">
 [% ELSE %]
 <label for="searchfieldstype_filter">Campos de pesquisa:</label>
 <select name="searchfieldstype" id="searchfieldstype_filter">
 [% END %]
 [% SET standard = Koha.Preference('DefaultPatronSearchFields') || 'firstname,middle_name,surname,othernames,cardnumber,userid' %]
 [% SET full_address = 'streetnumber,streettype,address,address2,city,state,zipcode,country' %]
 [% SET all_emails = 'email,emailpro,B_email' %]
 [% SET all_phones = 'phone,phonepro,B_phone,altcontactphone,mobile' %]
 [% default_fields = [ standard, 'surname', 'cardnumber', all_emails, 'borrowernumber', 'userid', all_phones, full_address, 'dateofbirth', 'sort1', 'sort2' ] %]
 [% search_options = default_fields.merge(standard.split(',')).unique %]
 [% FOREACH s_o IN search_options %]
 [% display_name = PROCESS patron_fields name=s_o %]
 [% NEXT IF !display_name %]
 [% IF searchfieldstype == s_o %]
 <option selected="selected" value=[% s_o | html %]>[% display_name | $raw %]</option>
 [% ELSE %]
 <option value=[% s_o | html %]>[% display_name | $raw %]</option>
 [% END %]
 [% END %]
 </select>
[%- END -%]
