# $NetBSD$

.PHONY: rpath-usr-lib
do-regress: rpath-usr-lib
rpath-usr-lib:
	@test="${COMPILER_RPATH_FLAG}/usr/lib";				\
	expected="";							\
	${TEST_RESULT}
