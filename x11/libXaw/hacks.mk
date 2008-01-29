# $NetBSD: hacks.mk,v 1.1 2008/01/29 03:37:02 bjs Exp $

.if !defined(LIBXAW_HACKS_MK)
LIBXAW_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
