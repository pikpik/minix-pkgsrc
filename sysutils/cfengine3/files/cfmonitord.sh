#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfmonitord.sh,v 1.1.1.1 2010/11/05 13:57:21 pettai Exp $

# PROVIDE: cfmonitord

. /etc/rc.subr

name="cfmonitord"
rcvar=$name
command="@PREFIX@/sbin/cf-monitord"
required_files="/var/cfengine/inputs/promises.cf"

load_rc_config $name
run_rc_command "$1"
