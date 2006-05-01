#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: cherokee
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="cherokee"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="&"
required_files="@PKG_SYSCONFDIR@/cherokee/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${cherokee_flags} ${command_args}
fi
