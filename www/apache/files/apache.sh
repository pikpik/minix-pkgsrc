#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl start
 echo -n ' apache'
fi
exit 0
