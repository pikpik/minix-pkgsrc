# $NetBSD$

.PHONY: libdir-usr-lib-subdir
do-regress: libdir-usr-lib-subdir
libdir-usr-lib-subdir:
	@test="-L/usr/lib/i18n";					\
	expected="-L/usr/lib/i18n";					\
	${TEST_RESULT}
