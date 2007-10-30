#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: timsieved
# REQUIRE: 

. /etc/rc.subr

name="timsieved"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-timsieved"
pidfile="/var/run/dbmail-timsieved.pid"

load_rc_config $name
run_rc_command "$1"
