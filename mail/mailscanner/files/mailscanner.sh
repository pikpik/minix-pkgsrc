#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD$
#
# PROVIDE: mailscanner
# REQUIRE: LOGIN

. /etc/rc.subr

name="MailScanner"
rcvar="mailscanner"
start_cmd="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
