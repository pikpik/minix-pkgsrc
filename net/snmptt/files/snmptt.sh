#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snmptt.sh,v 1.4 2004/05/31 11:47:29 tron Exp $
#
# PROVIDE: snmptt
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="snmptt"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
command_interpreter="@PREFIX@/bin/perl"

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
        load_rc_config $name
        run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command}
fi
