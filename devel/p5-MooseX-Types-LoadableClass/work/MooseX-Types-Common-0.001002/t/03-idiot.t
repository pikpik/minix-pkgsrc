use strict;
use warnings;

use Test::More;

# Test for a warning when you make the stupid mistake I make all the time
# of saying use MooseX::Types::Common qw/NonEmptySimpleStr/;

BEGIN {
    eval { require Capture::Tiny }
        or plan skip_all => 'Capture::Tiny needed for these tests';
}

plan tests => 4;

use_ok 'MooseX::Types::Common';

my ($stdout, $stderr) = Capture::Tiny::capture(sub {
    MooseX::Types::Common->import;
});
is $stderr, '', 'No warning if nothing imported';

($stdout, $stderr) = Capture::Tiny::capture(sub {
    MooseX::Types::Common->import('NonEmptySimpleStr');
});
like $stderr, qr/Did you mean/, 'Got warning';
like $stderr, qr/NonEmptySimpleStr/, 'Warning mentions bad type';

