#!/bin/sh
#
# $NetBSD: apache.sh,v 1.2 1999/05/11 18:38:31 tron Exp $
#

CMD=${1:-start}

if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl $CMD >/dev/null
 echo -n ' apache'
fi
exit 0
