# $NetBSD$

.PHONY: preserve-option
do-regress: preserve-option
preserve-option:
	@test="-O2ABC";							\
	expected="-O2ABC";						\
	${TEST_RESULT}
