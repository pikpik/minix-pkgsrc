#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: mailgraph
# REQUIRE: DAEMON

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
command_interpreter="@PERL@"
command="@PREFIX@/sbin/mailgraph"
command_args="-d"

load_rc_config $name
run_rc_command "$1"
