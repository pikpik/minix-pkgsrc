#!/bin/sh
#
# $NetBSD$
#

isdexecd=@PREFIX@/sbin/isdexecd
isectd=@PREFIX@/sbin/isectd

if [ -x ${isdexecd} -a -x ${isectd} ]; then
	@ECHO@ -n ' isect'
	${isdexecd} &
	${isectd} &
fi
exit 0
