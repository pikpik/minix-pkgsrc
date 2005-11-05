#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: nsd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="nsd"
rcvar=${name}

required_files="@PKG_SYSCONFDIR@/nsd/nsd.zones @NSDDB@"

command=/usr/pkg/sbin/${name}
pidfile=/var/run/${name}.pid

nsd_flags=${nsd_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
