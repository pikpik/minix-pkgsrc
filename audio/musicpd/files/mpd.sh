#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: mpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="mpd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/mpd.conf"

load_rc_config $name
run_rc_command "$1"
