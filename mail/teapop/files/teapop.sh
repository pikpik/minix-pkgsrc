#!@RCD_SCRIPTS_SHELL@
#
#       $NetBSD: teapop,v 1.1 2002/05/07 23:46:01 hubertf Exp $  
#
# PROVIDE: teapop 
# REQUIRE: DAEMON
 
. /etc/rc.subr

name="teapop"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="-s"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/teapop.passwd"
sig_stop="INT"

load_rc_config $name
run_rc_command "$1"
