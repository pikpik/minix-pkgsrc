#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: distccd
# BEFORE:  DAEMON

. /etc/rc.subr

name="distccd"
rcvar=$name
command="/usr/pkg/bin/${name}"
command_args='--daemon --pid-file /var/run/distccd.pid --user nobody'

load_rc_config $name
run_rc_command "$1"
