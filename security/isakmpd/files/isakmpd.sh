#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isakmpd.sh,v 1.1 2002/04/04 09:42:30 martti Exp $
#
# PROVIDE: isakmpd
# REQUIRE: DAEMON NETWORK
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="isakmpd"
rcvar="${name}"
command="@PREFIX@/sbin/isakmpd"
pidfile="/var/run/isakmpd.pid"
required_files="@PKG_SYSCONFDIR@/isakmpd.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config "${name}"
	run_rc_command "$1"
else
	printf " ${name}"
	eval ${command} ${isakmpd_flags} ${command_args}
fi
