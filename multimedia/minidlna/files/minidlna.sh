#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: minidlna
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="minidlna"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
requre_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config ${name}

pidfile="/var/run/minidlna.pid"

run_rc_command $1
