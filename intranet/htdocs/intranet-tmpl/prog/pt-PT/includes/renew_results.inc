[% IF renew_results && renew_results.size > 0 %]
 <div class="alert">
 As multas dos seguintes exemplares foram pagas, os resultados de renovação são mostrados abaixo: [% FOREACH result IN renew_results %] [% IF result.success %] <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): Renovado - data de devolução [% result.info | html %]</p>
 [% ELSE %]
 <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): Não renovável - [% INCLUDE 'renew_strings.inc' error=result.info %]</p>
 [% END %]
 [% END %]
 </div>
[% END %]
