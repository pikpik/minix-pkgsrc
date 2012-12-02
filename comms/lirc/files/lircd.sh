#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: lircd
# REQUIRE: LOGIN

. /etc/rc.subr

name="lircd"
lircd_flags=${lircd_flags--H default -d /dev/lirc0}
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/lirc/${name}.pid"
required_files="@PKG_SYSCONFDIR@/lircd.conf"

load_rc_config $name
run_rc_command "$1"
