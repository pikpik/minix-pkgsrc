#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="tofmipd"
rcvar=$name
command="@PREFIX@/bin/tmda-ofmipd"
command_interpreter="@PYTHONBIN@"

load_rc_config $name
run_rc_command "$1"
