#!/bin/sh
#
# $NetBSD$
#
# PROVIDE: rplayd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="rplayd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@CONFDIR@/rplay.conf"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${rplayd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
