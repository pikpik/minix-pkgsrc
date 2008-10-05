# $NetBSD$

BUILTIN_PKG:=	scrnsaverproto
PKGCONFIG_FILE.scrnsaverproto=	${X11BASE}/lib/pkgconfig/scrnsaverproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
