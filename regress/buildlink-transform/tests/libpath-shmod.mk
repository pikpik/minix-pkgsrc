# $NetBSD$

.PHONY: libpath-shmod
do-regress: libpath-shmod
libpath-shmod:
	@test="${LOCALBASE}/lib/module/foo.so";				\
	expected="${LOCALBASE}/lib/module/foo.so";			\
	${TEST_RESULT}
