#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: vpnc
# REQUIRE: NETWORKING

[ -f /etc/rc.subr ] && . /etc/rc.subr

name="vpnc"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
vpnc_flags="--pid-file ${pidfile}"

load_rc_config $name
run_rc_command "$1"
