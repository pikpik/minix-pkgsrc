#!/bin/sh
#
# $NetBSD$

smbd=__PREFIX__/sbin/smbd
nmbd=__PREFIX__/sbin/nmbd

if [ -f ${smbd} ]; then
	__ECHO__ -n ' samba'
	${smbd} -D
	${nmbd} -D
fi
