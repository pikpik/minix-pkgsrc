#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="dbus"
rcvar=$name
command="@PREFIX@/bin/dbus-daemon-1"
command_args="--system"
required_dirs="@VARBASE@/run/dbus"
pidfile="@VARBASE@/run/dbus/pid"
dbus_user=messagebus
dbus_group=messagebus

load_rc_config $name
run_rc_command "$1"
