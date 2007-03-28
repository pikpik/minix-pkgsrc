#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mailman.sh,v 1.1 2004/09/06 06:29:42 lukem Exp $
#
# PROVIDE: task_manager
# REQUIRE: sympa
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="task_manager"
rcvar=$name
command="@PREFIX@/sympa/bin/task_manager.pl"
pidfile="/var/sympa/run/task_manager.pid"
command_interpreter="@PREFIX@/bin/perl"
sympa_user="sympa"

load_rc_config $name
run_rc_command "$1"
