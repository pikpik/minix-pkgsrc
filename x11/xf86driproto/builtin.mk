# $NetBSD$

BUILTIN_PKG:=	xf86driproto
PKGCONFIG_FILE.xf86driproto=	${X11BASE}/lib/pkgconfig/xf86driproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
