#! /bin/sh
#
# $NetBSD$
#
# PROVIDE: upsmon
# REQUIRE: upsd

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsmon"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@NUT_CONFDIR@/${name}.conf"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	${command} ${upsmon_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
