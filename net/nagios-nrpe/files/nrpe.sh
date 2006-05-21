#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: nrpe
# REQUIRE: DAEMON

. /etc/rc.subr

name="nrpe"
rcvar=$name
command="@PREFIX@/sbin/${name}"
config="@PKG_SYSCONFDIR@/${name}.cfg"
pidfile="/var/run/${name}.pid"

command_args="-c $config -d"

load_rc_config $name
run_rc_command "$1"
