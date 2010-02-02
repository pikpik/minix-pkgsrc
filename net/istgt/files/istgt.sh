#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: istgt
# REQUIRE: network mountcritlocal

$_rc_subr_loaded . /etc/rc.subr

name="istgt"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/istgt.conf"

load_rc_config $name
run_rc_command "$1"
