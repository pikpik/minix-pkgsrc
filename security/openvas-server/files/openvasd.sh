#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: openvasd
# REQUIRE: network
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="openvasd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-D -q"
pidfile="@VARBASE@/run/${name}.pid"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${openvasd_flags} ${command_args}
fi
