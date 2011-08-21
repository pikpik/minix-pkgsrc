# $NetBSD$

BUILTIN_PKG:=	renderproto
PKGCONFIG_FILE.renderproto=	${X11BASE}/lib/pkgconfig/renderproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
