#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: stunnel
# REQUIRE: LOGIN

. /etc/rc.subr

name="stunnel"
rcvar=$name
command="@PREFIX@/sbin/stunnel"
required_files="@PKG_SYSCONFDIR@/stunnel.conf"

load_rc_config $name
run_rc_command "$1"
