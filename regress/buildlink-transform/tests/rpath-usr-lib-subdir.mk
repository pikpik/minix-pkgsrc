# $NetBSD$

.PHONY: rpath-usr-lib-subdir
do-regress: rpath-usr-lib-subdir
rpath-usr-lib-subdir:
	@test="${COMPILER_RPATH_FLAG}/usr/lib/i18n";			\
	expected="${COMPILER_RPATH_FLAG}/usr/lib/i18n";			\
	${TEST_RESULT}
