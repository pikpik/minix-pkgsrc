#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: rsyncd
# REQUIRE: DAEMON

. /etc/rc.subr

name="rsyncd"
rcvar=$name
command="@PREFIX@/bin/rsync"
required_files="@PKG_SYSCONFDIR@/rsyncd.conf"

command_args="--daemon"

load_rc_config $name
run_rc_command "$1"
