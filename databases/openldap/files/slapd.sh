#! /bin/sh
#
# $NetBSD$
#
# OpenLDAP standalone LDAP daemon
#
# PROVIDE: slapd
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="slapd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
pidfile="/var/openldap/slapd.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${slapd_flags} ${command_args}
fi
