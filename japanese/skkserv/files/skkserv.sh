#!/bin/sh
#
#	$NetBSD: skkserv.sh,v 1.1.1.1 1999/12/24 03:19:23 itohy Exp $
#
# PROVIDE: skkserv
# REQUIRE: DAEMON
 
name="skkserv"
command="@PREFIX@/libexec/skkserv"
pidfile=""

cmd=${1:-start}

case ${cmd} in
start)
	if [ -x ${command}  ]; then
		echo "Starting ${name}."
		${command} 2>&1 > /dev/null
	fi
	;;
*)
	if [ -x ${command} ]; then
		${command} ${cmd} 2>&1 > /dev/null
	fi
	;;
esac
