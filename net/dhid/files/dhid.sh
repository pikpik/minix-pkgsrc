#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: dhid
# REQUIRE: NETWORK

. /etc/rc.subr

name="dhid"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dhid.conf"

load_rc_config $name
run_rc_command "$1"
