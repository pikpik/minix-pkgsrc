#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: proftpd
# REQUIRE: DAEMON LOGIN network
# KEYWORD: shutdown

. /etc/rc.subr

name="proftpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/proftpd.conf"

load_rc_config $name
run_rc_command "$1"
