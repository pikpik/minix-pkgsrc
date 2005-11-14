#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smbd.sh,v 1.10 2004/01/11 02:26:31 jlam Exp $
#
# PROVIDE: smbd
# REQUIRE: nmbd

. /etc/rc.subr

name="smbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_vars="nmbd"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

load_rc_config $name
load_rc_config_var nmbd nmbd
run_rc_command "$1"
