#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: perdition
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

procname="perdition.imap4"
name="perdition_imap4"
rcvar=$name
command="@PREFIX@/sbin/${procname}"
pidfile="/var/run/${procname}/${procname}.pid"

load_rc_config $name
run_rc_command "$1"
