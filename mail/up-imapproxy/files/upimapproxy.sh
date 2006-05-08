#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: upimapproxy
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upimapproxy"
rcvar=$name
command="@PREFIX@/sbin/in.imapproxyd"
required_files="@PKG_SYSCONFDIR@/imapproxy.conf"

load_rc_config $name
run_rc_command "$1"
