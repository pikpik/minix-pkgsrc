#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: qpopper
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name=qpopper
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
