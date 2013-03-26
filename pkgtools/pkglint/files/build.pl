#! @PERL@
# $NetBSD$
#

use strict;
use warnings;

sub readfile {
	my $file = shift;

	local $/ = undef;
	open(my $in, "<", $file) || die "failed to read $file: $!";
	my $contents = <$in>;
	close($in) || die "failed to read $file: $!";

	return $contents;
}

while (my $line = <>) {
	if ($line =~ /^use PkgLint::(.+);$/) {
		print readfile("PkgLint/$1.pm");
	} else {
		print $line;
	}
}
