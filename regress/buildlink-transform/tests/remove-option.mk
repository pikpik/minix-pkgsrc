# $NetBSD$

.PHONY: remove-option
do-regress: remove-option
remove-option:
	@test="-O2 -O5 -O9";						\
	expected="";							\
	${TEST_RESULT}
