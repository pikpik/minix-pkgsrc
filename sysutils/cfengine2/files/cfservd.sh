#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$

# PROVIDE: cfservd
# REQUIRE: cfexecd

. /etc/rc.subr

name="cfservd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="/var/cfengine/inputs/cfservd.conf"

load_rc_config $name
run_rc_command "$1"
