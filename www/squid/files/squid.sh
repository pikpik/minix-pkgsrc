#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/sbin/RunCache -a -f @PREFIX@/etc/squid/squid.conf ];
then
 (cd /var/run; @PREFIX@/sbin/RunCache >/dev/null 2>&1 &)
 echo -n ' squid'
fi
exit 0
