#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: sqlgrey
# REQUIRE: DAEMON
# BEFORE: mail

. /etc/rc.subr

name="sqlgrey"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command_args="-d"
stop_cmd="${command} -k"

load_rc_config $name
run_rc_command "$1"
