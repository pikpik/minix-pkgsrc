#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: racoon
# REQUIRE: DAEMON LOGIN network
# KEYWORD: shutdown

. /etc/rc.subr

name="racoon"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/racoon.conf"
pidfile="/var/run/racoon.pid"

load_rc_config $name
run_rc_command "$1"
