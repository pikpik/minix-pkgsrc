#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: mailman
# REQUIRE: mail
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mailman"
rcvar=$name
ctl_command="@PREFIX@/lib/mailman/bin/mailmanctl"
start_cmd="mailman_doit start"
stop_cmd="mailman_doit stop"
restart_cmd="mailman_doit restart"

mailman_doit ()
{
	${ctl_command} $1
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	mailman_doit "$1"
fi
