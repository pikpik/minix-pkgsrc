# $NetBSD$

.PHONY: lib-expand
do-regress: lib-expand
lib-expand:
	@test="-lreadline";						\
	expected="-ledit -ltermcap -lm";				\
	${TEST_RESULT}
