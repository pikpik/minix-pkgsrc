# $NetBSD$

.PHONY: rpath-pkgsubdir
do-regress: rpath-pkgsubdir
rpath-pkgsubdir:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql";		\
	expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql";	\
	${TEST_RESULT}
