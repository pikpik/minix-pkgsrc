#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/sbin/exim ] ; then
	echo -n ' exim'
	@PREFIX@/sbin/exim -bd -q15m
fi
