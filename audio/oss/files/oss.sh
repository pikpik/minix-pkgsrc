#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: oss
# REQUIRE: aftermountlkm
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="oss"
rcvar=$name
required_files="/etc/oss.conf"
start_cmd="@PREFIX@/bin/soundon"
stop_cmd="@PREFIX@/bin/soundoff"

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	$start_cmd
fi

