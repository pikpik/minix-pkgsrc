#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slurpd.sh,v 1.1 2004/02/14 11:31:50 jlam Exp $
#
# OpenLDAP LDAP database replication daemon
#
# PROVIDE: slurpd
# REQUIRE: slapd

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="slurpd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
required_files="@OPENLDAP_ETCDIR@/slapd.conf"
required_vars="slapd"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${slurpd_flags} ${command_args}
fi
