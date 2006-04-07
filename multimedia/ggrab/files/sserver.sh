#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: sserver
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="sserver"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="</dev/null >/dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
