#!/bin/sh
# $NetBSD: arlad.sh,v 1.1.1.1 2000/06/08 15:56:28 wennmach Exp $
#
# start script for arlad (for NetBSD earlier than 1.5)

if [ -f @PREFIX@/libexec/arlad ]; then
	echo -n " arlad"
	@PREFIX@/libexec/arlad -z /dev/xfs0
fi
