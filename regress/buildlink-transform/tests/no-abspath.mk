# $NetBSD$

.PHONY: no-abspath
do-regress: no-abspath
no-abspath:
	@test="-L/bad/path/lib -I/bad/path/include ${COMPILER_RPATH_FLAG}/bad/path/lib"; \
	expected="";							\
	${TEST_RESULT}
