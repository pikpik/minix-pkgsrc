#!@SH@

# $NetBSD$

args="$@"
case "$args" in
*install*)
	install_args=
	case "$args" in
	*-destdir*) ;;
	*)
		install_args="${install_args} -destdir ${DESTDIR}@OCAML_FINDLIB_PREFIX@/lib/ocaml/site-lib"
		;;
	esac
	case "$args" in
	*-ldconf*) ;;
	*)
		install_args="${install_args} -ldconf @BUILDLINK_DIR@/lib/ocaml/ld.conf"
		;;
	esac
	args="${args%%install*}install ${install_args}${args##*install}"
	;;
*) ;;
esac

exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" ${args}
