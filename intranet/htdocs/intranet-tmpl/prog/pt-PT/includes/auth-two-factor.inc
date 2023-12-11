[% BLOCK registration_form %]
 <div id="registration-form" style="display: none;">
 <div class="dialog message">
 <p>Recomendamos o uso de aplicações móveis na nuvem como a Authy, Duo Mobile ou LastPass. Com essas aplicações é possível recuperar o acesso mesmo que perca o dispositivo.</p>
 <p>Não consegue ler o código?</p>
 <p>Para adicionar a entrada manualmente, insira os seguintes detalhes na aplicação no seu telemóvel.</p>
 <p>Conta: "<span id="issuer">[% issuer | html %]</span>: <span id="key_id">[% key_id | html %]</span>"</p>
 <p>Chave: "<span id="key_secret">[% secret32 | html %]</span>"</p>
 <p>Baseado no tempo: Sim</p>
 </div>

 <div id="errors" class="dialog error" style="display: none;"></div>

 <fieldset class="rows">
 <input type="hidden" id="secret32" name="secret32" value="[% secret32 | html %]" />
 <ol>
 <li>
 <label for="qr_code">Código QR: </label>
 <img id="qr_code" src="" />
 </li>
 <li>
 <label for="pin_code">Código PIN: </label>
 <input type="text" id="pin_code" name="pin_code" value="" />
 </li>
 </ol>
 </fieldset>
 <fieldset class="action">
 <input id="register-2FA" type="submit" value="Registar com aplicação dois-fatores" />
 <a class="cancel" href="/cgi-bin/koha/members/two_factor_auth.pl">Anular</a>
 </fieldset>
 </div>
[% END %]
