#!/bin/sh
#
# $NetBSD$

if [ -x @PREFIX@/sbin/rplayd ]; then
	echo -n ' rplayd';	@PREFIX@/sbin/rplayd
fi
