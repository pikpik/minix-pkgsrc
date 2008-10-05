# $NetBSD$

BUILTIN_PKG:=	xf86vidmodeproto
PKGCONFIG_FILE.xf86vidmodeproto=	${X11BASE}/lib/pkgconfig/xf86vidmodeproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
