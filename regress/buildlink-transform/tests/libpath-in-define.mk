# $NetBSD$

.PHONY: libpath-in-define
do-regress: libpath-in-define
libpath-in-define:
	@test="-DFOO=\"${LOCALBASE}/lib/libfoo.la\"";			\
	expected="-DFOO=\"${LOCALBASE}/lib/libfoo.la\"";		\
	${TEST_RESULT}
