package Koha::REST::V1::SearchFilter;

# This file is part of Koha.
#
# Koha is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3 of the License, or (at your option) any later
# version.
#
# Koha is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.

use Modern::Perl;

use Mojo::Base 'Mojolicious::Controller';
use Koha::SearchFilters;

use Try::Tiny qw( catch try );

=head1 Name

Koha::REST::V1::SearchFilters

=head1 API

=head2 Methods

=head3 list

Controller function that handles listing Koha::SearchFilter objects

=cut

sub list {
    my $c = shift->openapi->valid_input or return;
    return try {
        my $filters = $c->objects->search( Koha::SearchFilters->new );
        return $c->render(
            status  => 200,
            openapi => $filters
        );
    }
    catch {
        $c->unhandled_exception($_);
    };

}

=head3 get

Controller function that handles retrieving a single Koha::AdvancedEditorMacro

=cut

sub get {
    my $c = shift->openapi->valid_input or return;
    my $filter = Koha::SearchFilters->find( $c->param('search_filter_id') );
    unless ($filter) {
        return $c->render( status  => 404,
                           openapi => { error => "Search filter not found" } );
    }

    return $c->render( status => 200, openapi => $filter->to_api );
}

=head3 add

Controller function that handles adding a new Koha::SearchFilter object

=cut

sub add {
    my $c = shift->openapi->valid_input or return;

    return try {
        my $filter = Koha::SearchFilter->new_from_api( $c->req->json );
        $filter->store->discard_changes;
        $c->res->headers->location( $c->req->url->to_string . '/' . $filter->id );
        return $c->render(
            status  => 201,
            openapi => $filter->to_api
        );
    }
    catch {
        if ( blessed $_ and $_->isa('Koha::Exceptions::Object::DuplicateID') ) {
            return $c->render(
                status  => 409,
                openapi => { error => $_->error, conflict => $_->duplicate_id }
            );
        }
        $c->unhandled_exception($_);
    };
}

=head3 update

Controller function that handles updating a Koha::SearchFilter object

=cut

sub update {
    my $c = shift->openapi->valid_input or return;

    my $filter = Koha::SearchFilters->find( $c->param('search_filter_id') );

    if ( not defined $filter ) {
        return $c->render( status  => 404,
                           openapi => { error => "Object not found" } );
    }

    return try {
        $filter->set_from_api( $c->req->json );
        $filter->store->discard_changes;
        return $c->render( status => 200, openapi => $filter->to_api );
    }
    catch {
        $c->unhandled_exception($_);
    };
}

=head3 delete

Controller function that handles deleting a Koha::SearchFilter object

=cut

sub delete {
    my $c = shift->openapi->valid_input or return;

    my $filter = Koha::SearchFilters->find( $c->param('search_filter_id') );
    if ( not defined $filter ) {
        return $c->render( status  => 404,
                           openapi => { error => "Object not found" } );
    }

    return try {
        $filter->delete;
        return $c->render( status => 204, openapi => q{} );
    }
    catch {
        $c->unhandled_exception($_);
    };
}

1;
