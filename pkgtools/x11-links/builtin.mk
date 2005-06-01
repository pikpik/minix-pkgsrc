# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:30 jlam Exp $

BUILTIN_PKG:=	x11-links
.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(USE_BUILTIN.x11-links)
USE_BUILTIN.x11-links=	no
.endif
MAKEVARS+=	USE_BUILTIN.x11-links
