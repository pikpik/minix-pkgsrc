#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: bosserver
# BEFORE: arlad
# REQUIRE: NETWORK

. /etc/rc.subr

name="bosserver"
rcvar=$name
hostname=`@HOSTNAME_CMD@`
command="@PREFIX@/sbin/$name"
stop_precmd="@PREFIX@/bin/bos shutdown $hostname -local -wait"

load_rc_config $name
run_rc_command "$1"
