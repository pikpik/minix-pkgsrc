#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: daapd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="daapd"
help_name=$name
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/daapd.conf"
command_args="-c $required_files 2>&1 > /dev/null &"
# pidfile="@JABBERD_PIDDIR@/${help_name}.pid"
# jabberd_user="@JABBERD_USER@"

load_rc_config $name
run_rc_command "$1"
