#!/bin/sh
#
# $NetBSD$
#
# PROVIDE: dynipclient
# REQUIRE: NETWORK

. /etc/rc.subr

name="dynipclient"
rcvar=$name
command="/usr/pkg/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="/etc/dynip.cfg"

load_rc_config $name
run_rc_command "$1"
