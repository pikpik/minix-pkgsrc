#!/bin/sh
#
# $NetBSD: $
#

# PROVIDE: xenbackendd
# REQUIRE: xend

$_rc_subr_loaded . /etc/rc.subr

name="xenbackendd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
