#!/bin/sh
#
# $NetBSD: samba.sh,v 1.1 1999/11/16 21:01:05 jlam Exp $

smbd=@PREFIX@/sbin/smbd
nmbd=@PREFIX@/sbin/nmbd

if [ -f ${smbd} ]; then
	@ECHO@ -n ' samba'
	${smbd} -D
	${nmbd} -D
fi
