[% SWITCH Koha.Preference('CSVDelimiter') %]
 [% CASE '#' %]<span>Texto separado por cardinais (.csv)</span>
 [% CASE ',' %]<span>Texto separado por vírgulas (.csv)</span>
 [% CASE '/' %]<span>Texto separado por barras (.csv)</span>
 [% CASE ';' %]<span>Texto separado por ponto e vírgulas (.csv)</span>
 [% CASE '\\' %]<span>Texto separado por barras invertidas (.csv)</span>
 [% CASE 'tabulation' %]<span>Texto separado por tabulações (.csv)</span>
[% END %]
