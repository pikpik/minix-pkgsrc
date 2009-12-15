# $NetBSD$

.include "../../mk/compiler.mk"

.if ${PKGSRC_COMPILER} == "ido"
CPPFLAGS+=	-DNO_ATTRIBUTE
.endif
