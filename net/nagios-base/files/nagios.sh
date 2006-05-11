#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nagios.sh,v 1.1.1.1 2006/02/18 17:12:20 bouyer Exp $
#
# PROVIDE: nagios
# REQUIRE: DAEMON

. /etc/rc.subr

name="nagios"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}/${name}.lock"
config="@PKG_SYSCONFDIR@/${name}.cfg"

command_args="-d $config"
 
test_cmd="nagios_test"
extra_commands="test"

nagios_test()
{
	$command -v $config
}

load_rc_config $name
run_rc_command "$1"
