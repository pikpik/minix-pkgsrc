#!/bin/sh
# $NetBSD$
if [ -f @PREFIX@/bin/xdm-krb4 ]; then
	echo -n " xdm-krb4"
	@PREFIX@/bin/xdm-krb4
elif [-f @PREFIX@/bin/xdm ]; then
# Fallback to xdm when xdm-krb4 is unavailable
	echo -n " xdm(fallback for xdm-krb4)"
	@PREFIX@/bin/xdm
else echo " WARNING: no xdm found."
fi
