# $NetBSD$

.PHONY: libpath
do-regress: libpath
libpath:
	@test="${LOCALBASE}/lib/libfoo.la";				\
	expected="${BUILDLINK_DIR}/lib/libfoo.la";			\
	${TEST_RESULT}
