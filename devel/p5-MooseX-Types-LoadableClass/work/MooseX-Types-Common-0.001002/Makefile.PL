#!/usr/bin/perl -w
use strict;
use inc::Module::Install;

name 'MooseX-Types-Common';
license 'perl';
all_from 'lib/MooseX/Types/Common.pm';

# prereqs
requires 'Moose' => '0.39';
requires 'MooseX::Types' => '0.04';

# things the tests need
test_requires 'Test::More' => '0.62';
test_requires 'Test::Exception';

resources 'IRC' => 'irc://irc.perl.org/#moose';
resources 'license' => 'http://dev.perl.org/licenses/';
resources 'repository' => 'git://git.moose.perl.org/MooseX-Types-Common.git';

WriteAll;
