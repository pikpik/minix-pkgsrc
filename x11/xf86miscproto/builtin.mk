# $NetBSD$

BUILTIN_PKG:=	xf86miscproto
PKGCONFIG_FILE.xf86miscproto=	${X11BASE}/lib/pkgconfig/xf86miscproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
