# $NetBSD$

.PHONY: repeated-arg
do-regress: repeated-arg
repeated-arg:
	@test="-L${LOCALBASE}/lib -L${LOCALBASE}/lib";			\
	expected="-L${BUILDLINK_DIR}/lib";				\
	${TEST_RESULT}
