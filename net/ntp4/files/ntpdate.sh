#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ntpdate,v 1.8 2002/03/22 04:16:39 lukem Exp $
#

# PROVIDE: ntpdate
# REQUIRE: NETWORKING syslogd

. /etc/rc.subr

name="ntpdate"
rcvar=$name
start_cmd="ntpdate_start"
stop_cmd=":"

ntpdate_start()
{
	if [ -z "$ntpdate_hosts" ]; then
		ntpdate_hosts=`awk '
		    /^server[ \t]*127.127/	{next}
		    /^(server|peer)/		{print $2}
		' <@PKG_SYSCONFDIR@/ntp.conf`
	fi
	if [ -n "$ntpdate_hosts"  ]; then
		echo "Setting date via ntp."
		@PREFIX@/bin/ntpdate $rc_flags $ntpdate_hosts
	fi
}

load_rc_config $name
run_rc_command "$1"
