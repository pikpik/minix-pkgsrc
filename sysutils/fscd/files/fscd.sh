#!/bin/sh
#
# $Id: fscd 1691 2010-06-17 19:36:16Z bsdtrhodes $
#
# Startup script for service monitoring daemon.
#

# PROVIDE: fscd
# REQUIRE: DAEMON syslogd
# BEFORE:  NETWORKING LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="fscd"
rcvar=${name}
pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
