#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: unbound
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="unbound"
rcvar=${name}

command=@PREFIX@/sbin/${name}
pidfile=/var/run/${name}.pid

load_rc_config ${name}
run_rc_command "$1"
