# $NetBSD$

.PHONY: rpath-pkgdir
do-regress: rpath-pkgdir
rpath-pkgdir:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";			\
	expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";		\
	${TEST_RESULT}
