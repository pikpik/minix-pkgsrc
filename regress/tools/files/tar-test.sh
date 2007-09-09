#! /bin/sh
# $NetBSD: awk-test.sh,v 1.8 2006/05/31 13:10:49 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the tar testsuite.
#

# none.

#
# The actual test.
#

# tar must support the -z option.
#
testcase_start "-z"
echo "data" > file
tar cfz archive.tar.gz file
