#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upclient.sh,v 1.7 2003/07/30 17:56:43 jmmv Exp $
#
# PROVIDE: whosond
# REQUIRE: NETWORK
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="whosond"
rcvar="${name}"
command="@PREFIX@/sbin/whosond"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf ' whosond'
	${command} ${whosond_flags} ${command_args}
fi
