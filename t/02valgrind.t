#!/usr/bin/perl

# t/02valgrind.t
#  Tests that there are no memory leaks
#
# By Jonathan Yu <frequency@cpan.org>, 2009. All rights reversed.
#
# $Id: 02valgrind.t 6044 2009-04-07 02:33:01Z FREQUENCY@cpan.org $
#
# This package and its contents are released by the author into the
# Public Domain, to the full extent permissible by law. For additional
# information, please see the included `LICENSE' file.

use strict;
use warnings;

use Test::More;

unless ($ENV{TEST_AUTHOR}) {
  plan skip_all => 'Set TEST_AUTHOR to enable module author tests';
}

eval {
  require Test::Valgrind;
};
if ($@) {
  plan skip_all => 'Test::Valgrind required to test memory leaks';
}

plan tests => 2;

use Math::Random::ISAAC::XS ();

Test::Valgrind->import(diag => 1);

my $rng = Math::Random::ISAAC::XS->new(time);
$rng->irand() for (0..10);
$rng->rand() for (0..10);
