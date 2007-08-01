#! /bin/sh
#
# $NetBSD$
#
# Please read subr.sh for a brief explanation of how this works.

[ -z "$CC" ] && CC=gcc
[ -z "$CPP" ] && CPP="$CC -E"

HEADERS="math.h resolv.h stdlib.h stdint.h sys/select.h"

. ./subr.sh

for hdr in $HEADERS
do
	make_header $hdr
done
