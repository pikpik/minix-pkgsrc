# $NetBSD$

.PHONY: libdir-pkgdir
do-regress: libdir-pkgdir
libdir-pkgdir:
	@test="-L${LOCALBASE}/lib";					\
	expected="-L${BUILDLINK_DIR}/lib";				\
	${TEST_RESULT}
