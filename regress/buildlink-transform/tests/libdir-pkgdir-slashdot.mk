# $NetBSD$

.PHONY: libdir-pkgdir-slashdot
do-regress: libdir-pkgdir-slashdot
libdir-pkgdir-slashdot:
	@test="-L${LOCALBASE}/lib/.";					\
	expected="-L${BUILDLINK_DIR}/lib";				\
	${TEST_RESULT}
