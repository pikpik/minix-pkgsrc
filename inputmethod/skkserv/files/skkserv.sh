#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: skkserv.sh,v 1.2 2003/07/29 22:08:29 jmmv Exp $
#
# PROVIDE: skkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="skkserv"
rcvar=$name
command="@PREFIX@/libexec/${name}"

load_rc_config $name
run_rc_command "$1"
