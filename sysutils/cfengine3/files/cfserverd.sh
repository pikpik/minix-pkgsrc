#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$

# PROVIDE: cfserverd

. /etc/rc.subr

name="cfserverd"
rcvar=$name
command="@PREFIX@/sbin/cf-serverd"
required_files="/var/cfengine/inputs/site.cf"

load_rc_config $name
run_rc_command "$1"
