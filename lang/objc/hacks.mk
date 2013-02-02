# $NetBSD$

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D__attribute__\(x\)=
.endif
