#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/sbin/wwwoffled -a -f @PREFIX@/etc/wwwoffle/wwwoffle.conf ];
then
 @PREFIX@/sbin/wwwoffled -c @PREFIX@/etc/wwwoffle/wwwoffle.conf >/dev/null 2>&1 &
 echo -n ' wwwoffled'
fi
exit 0
