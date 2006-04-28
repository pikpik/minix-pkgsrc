#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# Courier core processes 
#
# PROVIDE: courierd
# REQUIRE: courierfilter courierldapaliasd
# KEYWORD: shutdown

. /etc/rc.subr

name="courierd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
ctl_command="@PREFIX@/sbin/courier"

restart_cmd="courier_doit restart"
start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1

	case $action in
	restart)
		@ECHO@ "Restarting ${name}."
		;;
	start)
		@TEST@ -f @PKG_SYSCONFDIR@/aliases.dat ||
			@PREFIX@/sbin/makealiases
		@ECHO@ "Starting ${name}."
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		;;
	esac

	${ctl_command} $action
}

load_rc_config $name
run_rc_command "$1"
