# $NetBSD$

.PHONY: libdir-pkgsubdir
do-regress: libdir-pkgsubdir
libdir-pkgsubdir:
	@test="-L${LOCALBASE}/lib/mysql";				\
	expected="-L${BUILDLINK_DIR}/lib/mysql";			\
	${TEST_RESULT}
