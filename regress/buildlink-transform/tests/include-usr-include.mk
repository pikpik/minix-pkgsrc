# $NetBSD$

.PHONY: include-usr-include
do-regress: include-usr-include
include-usr-include:
	@test="-I/usr/include";						\
	expected="";							\
	${TEST_RESULT}
