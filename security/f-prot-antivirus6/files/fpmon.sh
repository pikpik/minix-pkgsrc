#!@RCD_SCRIPTS_SHELL@
# $NetBSD$

# PROVIDE: fpmon
# REQUIRE: DAEMON fpscand

. /etc/rc.subr

name="fpmon"
rcvar=$name
conf="@PKG_SYSCONFDIR@/f-prot.conf"
command="@PREFIX@/@FPROTDIR@/fpmon"
required_files="${conf} ${command}"
start_cmd="fpmon_start"

fpmon_start()
{
	if [ -x ${command} ]; then
		${command} ${rc_flags}
	fi
}

load_rc_config $name
run_rc_command "$1"
