# $NetBSD$

BUILTIN_PKG:=	printproto
PKGCONFIG_FILE.printproto=	${X11BASE}/lib/pkgconfig/printproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
