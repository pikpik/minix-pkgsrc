#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/sbin/rtspd
then
 @PREFIX@/sbin/rtspd
 echo -n ' rtspd'
fi
exit 0
