#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: gld
# BEFORE: postfix
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="gld"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
pidfile="@VARBASE@/run/${name}.pid"

if [ "$1" != "stop" ]; then
	echo $(check_process $command) > $pidfile
fi

load_rc_config $name
run_rc_command "$1"
