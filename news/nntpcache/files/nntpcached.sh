#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: nntpcached
# REQUIRE: NETWORKING SERVERS
# KEYWORD: shutdown

. /etc/rc.subr

name="nntpcached"
rcvar=${name}
command="@PREFIX@/sbin/${name}"

load_rc_config ${name}
run_rc_command "$1"
