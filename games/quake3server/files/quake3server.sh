#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: quake3server
# REQUIRE: network mountcritlocal

. /etc/rc.subr

name="quake3server"
rcvar=$name
q3rootdir="@PREFIX@/lib/lokigames/quake3server"
command="${q3rootdir}/q3ded &"
extra_commands="reload"

cd ${q3rootdir}

load_rc_config $name
run_rc_command "$1"
