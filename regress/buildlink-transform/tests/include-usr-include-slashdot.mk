# $NetBSD$

.PHONY: include-usr-include-slashdot
do-regress: include-usr-include-slashdot
include-usr-include-slashdot:
	@test="-I/usr/include/.";					\
	expected="";							\
	${TEST_RESULT}
