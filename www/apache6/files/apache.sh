#!/bin/sh
#
# $NetBSD: apache.sh,v 1.1.1.1 1999/07/23 17:53:29 itojun Exp $
#

CMD=${1:-start}

if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl $CMD >/dev/null
 echo -n ' apache'
fi
exit 0
