#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/sbin/RunCache -a -f /etc/squid.conf ];
then
 @PREFIX@/sbin/RunCache >/dev/null 2>&1 &
 echo -n ' squid'
fi
exit 0
