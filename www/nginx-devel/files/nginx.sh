#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: nginx
# REQUIRE: DAEMON

. /etc/rc.subr

name="nginx"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"
start_precmd="ulimit -n 2048"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
