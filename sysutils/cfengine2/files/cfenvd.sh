#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$

# PROVIDE: cfenvd
# REQUIRE: cfexecd

. /etc/rc.subr

name="cfenvd"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
