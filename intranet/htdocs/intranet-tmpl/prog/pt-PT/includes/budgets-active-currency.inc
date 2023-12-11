[% IF ( currency ) %]
 [% IF ( not hide ) %]
 <p><strong>Moeda = [% currency | html %]</strong></p>
 [% END %]
[% ELSE %]
 <div class="dialog alert">
 <h3>Nenhuma moeda ativa definida</h3>
 [% IF CAN_user_acquisition_currencies_manage %]
 <p><a href="/cgi-bin/koha/admin/currency.pl">Por favor, especifique a moeda ativa.</a></p>
 [% ELSE %]
 <p>O administrador deve especificar uma moeda ativa.</p>
 [% END %]
 </div>
[% END %]
