#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: icecast
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="icecast"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-b -c @PKG_SYSCONFDIR@/$name.xml 1>2& >/dev/null"
required_files="@PKG_SYSCONFDIR@/$name.xml"

load_rc_config $name
run_rc_command "$1"
