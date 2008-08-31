#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: vmtools
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="vmtools"
rcvar="vmtools"
pidfile="/var/run/vmware-guestd.pid"
command="@PREFIX@/sbin/vmware-guestd"
command_args="--background ${pidfile}"

load_rc_config $name
run_rc_command "$1"
