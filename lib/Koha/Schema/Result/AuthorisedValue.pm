use utf8;
package Koha::Schema::Result::AuthorisedValue;

# Created by DBIx::Class::Schema::Loader
# DO NOT MODIFY THE FIRST PART OF THIS FILE

=head1 NAME

Koha::Schema::Result::AuthorisedValue

=cut

use strict;
use warnings;

use base 'DBIx::Class::Core';

=head1 TABLE: C<authorised_values>

=cut

__PACKAGE__->table("authorised_values");

=head1 ACCESSORS

=head2 id

  data_type: 'integer'
  is_auto_increment: 1
  is_nullable: 0

unique key, used to identify the authorized value

=head2 category

  data_type: 'varchar'
  default_value: (empty string)
  is_foreign_key: 1
  is_nullable: 0
  size: 32

key used to identify the authorized value category

=head2 authorised_value

  data_type: 'varchar'
  default_value: (empty string)
  is_nullable: 0
  size: 80

code use to identify the authorized value

=head2 lib

  data_type: 'varchar'
  is_nullable: 1
  size: 200

authorized value description as printed in the staff interface

=head2 lib_opac

  data_type: 'varchar'
  is_nullable: 1
  size: 200

authorized value description as printed in the OPAC

=head2 imageurl

  data_type: 'varchar'
  is_nullable: 1
  size: 200

authorized value URL

=cut

__PACKAGE__->add_columns(
  "id",
  { data_type => "integer", is_auto_increment => 1, is_nullable => 0 },
  "category",
  {
    data_type => "varchar",
    default_value => "",
    is_foreign_key => 1,
    is_nullable => 0,
    size => 32,
  },
  "authorised_value",
  { data_type => "varchar", default_value => "", is_nullable => 0, size => 80 },
  "lib",
  { data_type => "varchar", is_nullable => 1, size => 200 },
  "lib_opac",
  { data_type => "varchar", is_nullable => 1, size => 200 },
  "imageurl",
  { data_type => "varchar", is_nullable => 1, size => 200 },
);

=head1 PRIMARY KEY

=over 4

=item * L</id>

=back

=cut

__PACKAGE__->set_primary_key("id");

=head1 UNIQUE CONSTRAINTS

=head2 C<av_uniq>

=over 4

=item * L</category>

=item * L</authorised_value>

=back

=cut

__PACKAGE__->add_unique_constraint("av_uniq", ["category", "authorised_value"]);

=head1 RELATIONS

=head2 authorised_values_branches

Type: has_many

Related object: L<Koha::Schema::Result::AuthorisedValuesBranch>

=cut

__PACKAGE__->has_many(
  "authorised_values_branches",
  "Koha::Schema::Result::AuthorisedValuesBranch",
  { "foreign.av_id" => "self.id" },
  { cascade_copy => 0, cascade_delete => 0 },
);

=head2 category

Type: belongs_to

Related object: L<Koha::Schema::Result::AuthorisedValueCategory>

=cut

__PACKAGE__->belongs_to(
  "category",
  "Koha::Schema::Result::AuthorisedValueCategory",
  { category_name => "category" },
  { is_deferrable => 1, on_delete => "CASCADE", on_update => "CASCADE" },
);

=head2 illrequests

Type: has_many

Related object: L<Koha::Schema::Result::Illrequest>

=cut

__PACKAGE__->has_many(
  "illrequests",
  "Koha::Schema::Result::Illrequest",
  { "foreign.status_alias" => "self.authorised_value" },
  { cascade_copy => 0, cascade_delete => 0 },
);


# Created by DBIx::Class::Schema::Loader v0.07049 @ 2021-01-21 13:39:29
# DO NOT MODIFY THIS OR ANYTHING ABOVE! md5sum:LH9dpEEzlVVsjNVv/jnONg


# You can replace this text with custom code or comments, and it will be preserved on regeneration
1;
