# $NetBSD: hacks.mk,v 1.2 2007/09/25 03:13:01 bjs Exp $

.if !defined(OSSP_JS_HACKS_MK)
OSSP_JS_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
