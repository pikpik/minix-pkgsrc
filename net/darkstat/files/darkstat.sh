#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: darkstat
# REQUIRE: NETWORKING named

. /etc/rc.subr

name="darkstat"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
