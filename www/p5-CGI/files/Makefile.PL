# $NetBSD: Makefile.PL,v 1.1.1.1 1998/11/26 17:57:03 bad Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'CGI',
    'DISTNAME'  => 'CGI.pm',
    'VERSION'   => '2.66',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
