# $NetBSD: rpath-pkgdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: rpath-pkgdir
do-regress: rpath-pkgdir
rpath-pkgdir:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";			\
	case "${_USE_RPATH}" in						\
	[yY][eE][sS])							\
		expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";	\
		;;							\
	*)								\
		expected="";						\
		;;							\
	esac;								\
	${TEST_RESULT}
