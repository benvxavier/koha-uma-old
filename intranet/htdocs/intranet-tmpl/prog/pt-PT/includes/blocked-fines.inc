[% USE Price %]
[% SET NoIssuesCharge = Koha.Preference('noissuescharge') %]
[% IF fines and fines > 0 %]
 <li>
 <span class="circ-hlt">Cobranças:</span>
 <span>O leitor tem multas pendentes de [% fines | $Price %].</span>
 [% IF !Koha.Preference('AllowFineOverride') && NoIssuesCharge && fines > NoIssuesCharge %]
 <span class="circ-hlt">Empréstimos BLOQUEADOS porque as multas do leitor ULTRAPASSAM O LIMITE.</span>
 [% END %]
 [% IF CAN_user_updatecharges_remaining_permissions %]
 <a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >Fazer pagamento</a>
 <a href="/cgi-bin/koha/members/paycollect.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >Pagar todas as multas</a>
 [% END %]
 </li>
[% END %]
