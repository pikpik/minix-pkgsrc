#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: inadyn
# REQUIRE: NETWORK

. /etc/rc.subr

name="inadyn"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/inadyn.conf"

load_rc_config $name
run_rc_command "$1"
