#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: miniupnpd
# REQUIRE: DAEMON @FWNAME@
# KEYWORD: shutdown

. /etc/rc.subr

name="miniupnpd"
rcvar=$name
command="@PREFIX@/sbin/miniupnpd"

load_rc_config $name
run_rc_command "$1"
