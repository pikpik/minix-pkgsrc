# $NetBSD$

.PHONY: libpath-shlib
do-regress: libpath-shlib
libpath-shlib:
	@test="${LOCALBASE}/lib/libfoo.so";				\
	expected="-L${BUILDLINK_DIR}/lib -lfoo";			\
	${TEST_RESULT}
