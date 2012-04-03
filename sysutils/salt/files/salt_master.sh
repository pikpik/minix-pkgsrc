#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: salt_master
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="salt_master"
rcvar=$name
command="@PREFIX@/bin/salt-master"
command_args="-d"
required_files="@PKG_SYSCONFDIR@/master"

load_rc_config $name
run_rc_command "$1"
