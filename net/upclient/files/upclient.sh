#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upclient.sh,v 1.6 2002/09/23 15:24:13 grant Exp $
#
# PROVIDE: upclient
# REQUIRE: NETWORK
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upclient"
rcvar="${name}"
command="@PREFIX@/bin/upclient"
upclient_user="nobody"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf ' upclient'
	${command} ${upclient_flags} ${command_args}
fi
