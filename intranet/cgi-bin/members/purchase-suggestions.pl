#!/usr/bin/perl

# This file is part of Koha.
#
# Copyright 2012 ByWater Solutions
#
# Koha is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Koha is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.

use Modern::Perl;

use CGI qw ( -utf8 );
use C4::Auth qw( get_template_and_user );
use C4::Context;
use C4::Output qw( output_and_exit_if_error output_and_exit output_html_with_http_headers );
use Koha::Patrons;
use Koha::Suggestions;

my $input = CGI->new;

my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {   template_name   => "members/purchase-suggestions.tt",
        query           => $input,
        type            => "intranet",
        flagsrequired   => { suggestions => 'suggestions_manage' },
    }
);

my $borrowernumber = $input->param('borrowernumber');

my $logged_in_user = Koha::Patrons->find( $loggedinuser );
my $patron         = Koha::Patrons->find( $borrowernumber );
output_and_exit_if_error( $input, $cookie, $template, { module => 'members', logged_in_user => $logged_in_user, current_patron => $patron } );

my $category = $patron->category;
$template->param(
    patron => $patron,
    suggestionsview  => 1,
);

my $suggestions = [
    Koha::Suggestions->search_limited( { suggestedby => $borrowernumber },
        { prefetch => 'managedby' } )->as_list
];

$template->param( suggestions => $suggestions );

output_html_with_http_headers $input, $cookie, $template->output;
