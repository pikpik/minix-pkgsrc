# $NetBSD$

BUILTIN_PKG:=	xf86bigfontproto
PKGCONFIG_FILE.xf86bigfontproto=	${X11BASE}/lib/pkgconfig/xf86bigfontproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
