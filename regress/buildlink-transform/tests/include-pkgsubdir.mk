# $NetBSD$

.PHONY: include-pkgsubdir
do-regress: include-pkgsubdir
include-pkgsubdir:
	@test="-I${LOCALBASE}/include/krb5";				\
	expected="-I${BUILDLINK_DIR}/include/krb5";			\
	${TEST_RESULT}
