#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$

# PROVIDE: miredo
# REQUIRE: NETWORKING

. /etc/rc.subr

name="miredo"
rcvar=$name
command="/usr/pkg/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"

