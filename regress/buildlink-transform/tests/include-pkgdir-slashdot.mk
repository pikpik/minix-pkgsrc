# $NetBSD$

.PHONY: include-pkgdir-slashdot
do-regress: include-pkgdir-slashdot
include-pkgdir-slashdot:
	@test="-I${LOCALBASE}/include/.";				\
	expected="-I${BUILDLINK_DIR}/include";				\
	${TEST_RESULT}
