#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zhm.sh,v 1.1.1.1 2002/12/30 17:39:27 sommerfeld Exp $
#
# PROVIDE: zhm
# REQUIRE: DAEMON

. /etc/rc.subr

name="zhm"
rcvar="$name"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/server.list"
start_precmd="zhm_precmd"

zhm_precmd()
{
	rc_flags="`cat @PKG_SYSCONFDIR@/server.list`"
}
load_rc_config "$name"
run_rc_command "$1"
