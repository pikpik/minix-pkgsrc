#!/bin/sh
# $NetBSD$

[ -x /usr/pkg/sbin/apachectl ] && /usr/pkg/sbin/apachectl start >/dev/null && echo -n ' apache'
