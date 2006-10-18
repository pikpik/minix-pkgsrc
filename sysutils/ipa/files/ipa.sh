#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ipa.sh,v 1.1 2003/05/30 11:53:17 salo Exp $
#

# If some IPA module requires some services, then they should
# be specified after REQUIRE, by default REQUIRE contains
# only syslogd, since ipa uses syslog for logging by default
# and does not require anything more for running.

# PROVIDE: ipa
# REQUIRE: syslogd
# BEFORE: LOGIN

. /etc/rc.subr

name="ipa"
rcvar=$name
command="@PREFIX@/bin/${name}"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
