#!/bin/sh
#
# $NetBSD$
#
# Dynamic DNS update client
#
# PROVIDE: ddclient
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ddclient"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PERL5@ @PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${ddclient_flags} ${command_args}
fi
