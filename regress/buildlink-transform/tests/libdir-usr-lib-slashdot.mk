# $NetBSD$

.PHONY: libdir-usr-lib-slashdot
do-regress: libdir-usr-lib-slashdot
libdir-usr-lib-slashdot:
	@test="-L/usr/lib/.";						\
	expected="";							\
	${TEST_RESULT}
