#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: kdc
# REQUIRE: NETWORKING
# BEFORE:  SERVERS

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="kdc"
rcvar=$name
command="@PREFIX@/libexec/${name}"
required_files="@PKG_SYSCONFDIR@/krb5.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${kdc_flags}
fi
