# $NetBSD$

.PHONY: libdir-usr-lib
do-regress: libdir-usr-lib
libdir-usr-lib:
	@test="-L/usr/lib";						\
	expected="";							\
	${TEST_RESULT}
