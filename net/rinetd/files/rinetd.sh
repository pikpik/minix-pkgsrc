#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: rinetd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

. /etc/rc.subr

name="rinetd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/rinetd.conf"

load_rc_config $name
run_rc_command "$1"
