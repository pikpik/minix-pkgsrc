#!/bin/sh
# $NetBSD: apache.sh,v 1.2 1998/09/05 09:08:08 explorer Exp $

[ -x @@@PREFIX@@@/sbin/apachectl ] && @@@PREFIX@@@/sbin/apachectl start >/dev/null && echo -n ' apache'
