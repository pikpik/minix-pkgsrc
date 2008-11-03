#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: mediatomb
# REQUIRE: DAEMON

. /etc/rc.subr

name="mediatomb"
rcvar=$name
command="@PREFIX@/bin/mediatomb"
logfile="@VARBASE@/log/${name}.log"
pidfile="@PKG_HOME@/${name}.pid"
command_args="-d -u @MEDIATOMB_USER@ -g @MEDIATOMB_USER@ -m @PKG_HOME@ -P ${pidfile} -l ${logfile} -f ."
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${mediatomb_flags} ${command_args}
fi
