<nav id="shortcut" class="shortcut">
 [% IF Koha.Preference('showLastPatron') %]
 [% INCLUDE 'last-borrower.inc' %]
 [% END %]

 <a class="toplinks" href="/cgi-bin/koha/help.pl" id="helper"><i class="fa fa-question-circle"></i> <span>Ajuda</span></a>
</nav>
