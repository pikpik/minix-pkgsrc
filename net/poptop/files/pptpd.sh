#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: pptpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="pptpd"
rcvar=$name
command="@PREFIX@/sbin/pptpd"
required_files="@PKG_SYSCONFDIR@/pptpd.conf"

load_rc_config $name
run_rc_command "$1"
