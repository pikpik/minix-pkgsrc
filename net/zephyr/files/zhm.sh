#!/bin/sh
#
# $NetBSD: zhm.sh,v 1.2 1998/08/07 11:11:06 agc Exp $
#
# PROVIDE: zhm
# REQUIRE: DAEMON

. /etc/rc.subr

PREFIX=${PREFIX-@prefix@}

name="zhm"
rcvar="$name"
command="${PREFIX}/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="${PREFIX}/etc/zephyr/server.list"
start_precmd="zhm_precmd"

zhm_precmd()
{
	_flags="`cat ${PREFIX}/etc/zephyr/server.list`"
}
load_rc_config "$name"
run_rc_command "$1"
