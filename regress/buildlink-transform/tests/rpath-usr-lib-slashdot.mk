# $NetBSD$

.PHONY: rpath-usr-lib-slashdot
do-regress: rpath-usr-lib-slashdot
rpath-usr-lib-slashdot:
	@test="${COMPILER_RPATH_FLAG}/usr/lib/.";			\
	expected="";							\
	${TEST_RESULT}
