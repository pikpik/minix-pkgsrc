# $NetBSD$

.PHONY: remove-dir
do-regress: remove-dir
remove-dir:
	@test="-L/opt/schily/lib -I/opt/schily/include";		\
	expected="";							\
	${TEST_RESULT}
