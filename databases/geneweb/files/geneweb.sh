#!/bin/sh
#
# $NetBSD$
#
if [ -x @PREFIX@/libexec/gwd ]
then
	@PREFIX@/libexec/gwd \
		-hd @PREFIX@/share/geneweb \
		-bd @PREFIX@/share/geneweb \
		-dd @PREFIX@/share/doc/geneweb \
		-log /var/log/geneweb.log \
		-lang en \
		-robot_xcl 100,150 \
		-daemon
		/bin/echo -n ' gwd'
fi
exit 0
