# $NetBSD$

.PHONY: quoted-arg
do-regress: quoted-arg
quoted-arg:
	@test='-D"DEFAULT_MODULE_PATH=\"${LOCALBASE}/lib/security/\""';	\
	expected='-D"DEFAULT_MODULE_PATH=\"${LOCALBASE}/lib/security/\""'; \
	${TEST_RESULT}
