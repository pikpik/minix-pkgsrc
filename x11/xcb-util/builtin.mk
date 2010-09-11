# $NetBSD: builtin.mk,v 1.2 2010/09/11 19:30:05 tron Exp $

BUILTIN_PKG:=	xcb-util
PKGCONFIG_FILE.xcb-util=	${X11BASE}/lib/pkgconfig/xcb-atom.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
