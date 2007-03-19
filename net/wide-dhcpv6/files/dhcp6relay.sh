#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: dhcp6relay
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dhcp6relay"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
