# $NetBSD$

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
PKG_HACKS+=		builtin-log
CFLAGS+=		-fno-builtin-log
.endif
