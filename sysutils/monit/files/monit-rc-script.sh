#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# Start script for 'monit'.
#

##
# PROVIDE: monit
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:@PREFIX@/bin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="monit"
rcvar=$name
command="@PREFIX@/bin/monit"
pidfile="@VARBASE@/run/${name}.pid"
statefile="@VARBASE@/run/${name}.state"
monitrc="@PKG_SYSCONFDIR@/monitrc"
extra_commands="reload"
sig_stop="TERM"
sig_reload="HUP"

monit_flags=${monit_flags-"-c ${monitrc} -p ${pidfile} -s ${statefile}"}

load_rc_config $name
run_rc_command "$1"
