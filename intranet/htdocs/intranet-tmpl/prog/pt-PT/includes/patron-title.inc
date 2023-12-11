[%- USE raw -%] [%- USE Koha -%] [%- USE Branches -%] [%- SET data = {} -%] [%- IF patron -%] [%- SET data.category_type  = patron.category.category_type -%] [%- SET data.surname        = patron.surname -%] [%- SET data.othernames     = patron.othernames -%] [%- SET data.firstname      = patron.firstname -%] [%- SET data.middle_name    = patron.middle_name -%] [%- SET data.cardnumber     = patron.cardnumber -%] [%- SET data.borrowernumber = patron.borrowernumber -%] [%- SET data.title          = patron.title -%] [%- ELSIF ( borrower.borrowernumber ) -%] [%- SET data.category_type  = borrower.category_type -%] [%- SET data.surname        = borrower.surname -%] [%- SET data.othernames     = borrower.othernames -%] [%- SET data.firstname      = borrower.firstname -%] [%- SET data.middle_name    = borrower.middle_name -%] [%- SET data.cardnumber     = borrower.cardnumber -%] [%- SET data.borrowernumber = borrower.borrowernumber -%] [%- SET data.title          = borrower.title -%] [%- ELSIF ( borrowernumber ) -%] [%- SET data.category_type  = category_type -%] [%- SET data.surname        = surname -%] [%- SET data.othernames     = othernames -%] [%- SET data.firstname      = firstname -%] [%- SET data.middle_name    = middle_name -%] [%- SET data.cardnumber     = cardnumber -%] [%- SET data.borrowernumber = borrowernumber -%] [%- SET data.title          = title -%] [%- END -%] [%# Parameter no_html - if 1, the html tags are NOT generated -%] [%- IF no_title -%][%- SET data.title = "" -%][%- END -%] [%- IF data.title -%] [%- IF no_html -%] [%- span_start = '' -%] [%- span_end   = '' -%] [%- ELSE -%] [%- span_start = '<span class="patron-title">' %] [%- span_end = '</span>' -%]
 [%- END -%]
 [%- data.title = data.title | html -%]
 [%- SET data.title = span_start _ data.title _ span_end _ ' ' -%]
[%- END -%]
[%- SET display_patron_name = 1 -%]
[%- SET display_cardnumber = 1 -%]
[%- IF no_cardnumber -%][%- SET display_cardnumber = 0 -%][%- END -%]
[%- IF hide_patron_infos_if_needed -%] [%# Should only be set if patron is set -%]
 [%- SET can_see_patron_infos = logged_in_user.can_see_patron_infos( patron ) -%]
 [%- UNLESS can_see_patron_infos -%]
 [%- SET display_patron_name = 0 -%]
 [%- SET display_cardnumber  = 0 -%]
 [%- ELSIF Koha.Preference('HidePatronName') -%]
 [%- SET display_patron_name = 0 -%]
 [%- END -%]
[%- END -%]
[%- IF hide_patron_infos_if_needed AND ( display_patron_name OR display_cardnumber ) -%]
 [%- IF link_to == 'circulation_reserves' -%]<a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[%- data.borrowernumber | uri -%]#reserves">
 [%- ELSIF link_to == 'circulation_recalls' -%]<a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[%- data.borrowernumber | uri -%]#recalls">
 [%- ELSIF link_to == 'members_pay' -%]<a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[%- patron.borrowernumber | uri -%]">
 [%- ELSE -%]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[%- data.borrowernumber | uri -%]">
 [%- END -%]
[%- END -%]
[%- IF display_patron_name -%]
 [%- IF data.category_type == 'I' -%]
 [%- data.surname | html -%] [%- IF data.othernames -%] ([%- data.othernames | html -%])[%- END -%]
 [%- ELSIF invert_name -%]
 [%- data.title | $raw -%][%- data.surname | html -%][%- IF ( data.firstname ) -%], [% data.firstname | html -%][%- END -%][%- IF data.middle_name -%] [% data.middle_name | html -%][%- END -%][%- IF data.othernames -%] ([%- data.othernames | html -%])[%- END -%]
 [%- ELSE -%]
 [%- data.title | $raw -%][%- data.firstname | html %][%- IF data.middle_name -%] [% data.middle_name | html -%][%- END -%][%- IF data.othernames -%] ([%- data.othernames | html -%]) [%- END -%] [% data.surname | html -%]
 [%- END -%]
 [%- IF display_cardnumber AND data.cardnumber -%] ([%- data.cardnumber | html -%])[%- END -%]
[%- ELSIF display_cardnumber -%]
 [%- IF data.cardnumber -%][%# FIXME Cardnumber should always be defined, right? -%]
 [%- data.cardnumber | html -%]
 [%- END -%]
[%- ELSE -%]
 <span>Um leitor da biblioteca [%- Branches.GetName( patron.branchcode ) | html -%]</span>
[%- END -%]

[%- IF hide_patron_infos_if_needed AND ( display_patron_name OR display_cardnumber ) -%]
 </a>
[%- END -%]