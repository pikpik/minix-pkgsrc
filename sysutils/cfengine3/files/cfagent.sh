#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$

# PROVIDE: cfagent

. /etc/rc.subr

name="cfagent"
rcvar=$name
command="@PREFIX@/sbin/cf-agent"
required_files="/var/cfengine/inputs/promises.cf"

load_rc_config $name
run_rc_command "$1"
