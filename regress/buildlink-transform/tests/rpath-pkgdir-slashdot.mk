# $NetBSD$

.PHONY: rpath-pkgdir-slashdot
do-regress: rpath-pkgdir-slashdot
rpath-pkgdir-slashdot:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/.";		\
	expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";		\
	${TEST_RESULT}
