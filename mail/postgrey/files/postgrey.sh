#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: postgrey
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
command_interpreter="@PERL@"
command="@PREFIX@/sbin/postgrey"
command_args="-d --pidfile=${pidfile}"
required_files="
 @PKG_SYSCONFDIR@/postgrey_whitelist_clients
 @PKG_SYSCONFDIR@/postgrey_whitelist_recipients
"
@PKGBASE@_flags=${@PKGBASE@_flags-"-i 2525"}

load_rc_config $name
run_rc_command "$1"
