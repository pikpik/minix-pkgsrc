#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: iasp_admin
# REQUIRE: iasp
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="iasp_admin"
rcvar=$name
start_cmd=iasp_admin_start
stop_cmd=iasp_admin_stop

iasp_admin_start()
{
	@IASP@/start-admin.sh &
	sleep 2
}

iasp_admin_stop()
{
	@IASP@/stop-admin.sh
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
        load_rc_config $name
        run_rc_command "$1"
else
        eval ${start_cmd}
fi
