#!/bin/sh
#
# $NetBSD$
#
# PROVIDE: stompserver
# REQUIRE: DAEMON

. /etc/rc.subr

name="stompserver"
rcvar=${name}
command="@PREFIX@/bin/stompserver"
required_files="@STOMPSERVER_RCD_CFG@/stompserver.conf"
pidfile="@STOMPSERVER_RCD_PID@"
command_args="-C @STOMPSERVER_RCD_CFG@/stompserver.conf"
procname="@RUBY@"

load_rc_config $name
run_rc_command "$1"
