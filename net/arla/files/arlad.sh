#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: arlad
# REQUIRE: beforemountlkm
# KEYWORD: shutdown

. /etc/rc.subr

name="arlad"
rcvar=$name
command="/usr/pkg/libexec/${name}"
command_args="-z /dev/nnpfs0"
required_files="/dev/nnpfs0"

load_rc_config $name
run_rc_command "$1"
