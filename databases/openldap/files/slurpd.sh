#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
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
required_files="@PKG_SYSCONFDIR@/slapd.conf"
required_vars="slapd"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${slurpd_flags} ${command_args}
fi
