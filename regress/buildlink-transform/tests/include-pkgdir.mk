# $NetBSD$

.PHONY: include-pkgdir
do-regress: include-pkgdir
include-pkgdir:
	@test="-I${LOCALBASE}/include";					\
	expected="-I${BUILDLINK_DIR}/include";				\
	${TEST_RESULT}
