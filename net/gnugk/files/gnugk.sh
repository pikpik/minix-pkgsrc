#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: gnugk
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="gnugk"
help_name="gnugk"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/gnugk.ini"
command_args="-c $required_files 2>&1 > /dev/null &"
# pidfile="@JABBERD_PIDDIR@/${help_name}.pid"
# jabberd_user="@JABBERD_USER@"

load_rc_config $name
run_rc_command "$1"
