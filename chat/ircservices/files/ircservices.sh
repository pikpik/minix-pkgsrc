#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: ircservices
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ircservices"
rcvar=$name
command="@PREFIX@/sbin/ircservices"
required_files="@PREFIX@/lib/services/ircservices.conf"
command_args=""

load_rc_config $name
run_rc_command "$1"
