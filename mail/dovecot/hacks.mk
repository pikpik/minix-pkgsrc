# $NetBSD: hacks.mk,v 1.1 2005/01/08 17:54:34 schmonz Exp $

.include "../../mk/compiler.mk"

# Avoid an ICE in gcc2 on sparc64
.if !empty(CC_VERSION:Mgcc-*)
PKG_HACKS+=		sparc64-gcc2-ice
CONFIGURE_ENV+=		F77=${FALSE}
.endif
