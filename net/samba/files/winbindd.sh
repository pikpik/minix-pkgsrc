#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: winbindd.sh,v 1.3 2005/12/21 04:17:53 jlam Exp $
#
# PROVIDE: winbindd
# REQUIRE: DAEMON

. /etc/rc.subr

name="winbindd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-B"

load_rc_config $name
run_rc_command "$1"
