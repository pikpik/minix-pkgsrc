#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: $
#

# PROVIDE: vmpsd
# REQUIRE: DAEMON

. /etc/rc.subr

name="vmpsd"
rcvar="vmpsd"
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/vlan.db"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
