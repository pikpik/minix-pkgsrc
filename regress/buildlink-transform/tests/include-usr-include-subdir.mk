# $NetBSD$

.PHONY: include-usr-include-subdir
do-regress: include-usr-include-subdir
include-usr-include-subdir:
	@test="-I/usr/include/krb5";					\
	expected="-I/usr/include/krb5";					\
	${TEST_RESULT}
