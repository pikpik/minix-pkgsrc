#!/bin/sh
# $NetBSD$
if [ -f @PREFIX@/sbin/arlad ]; then
	echo -n " arlad"
	@PREFIX@/sbin/arlad -z /dev/xfs0
fi
