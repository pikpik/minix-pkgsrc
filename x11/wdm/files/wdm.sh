#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: wdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="wdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/lib/X11/wdm/wdm-config"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
