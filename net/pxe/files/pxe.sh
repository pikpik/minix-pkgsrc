#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pxe,v 1.3 2002/09/23 15:11:41 grant Exp $
#
# PROVIDE: pxe
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pxe"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
