# $NetBSD$

BUILTIN_PKG:=	bigreqsproto
PKGCONFIG_FILE.bigreqsproto=	${X11BASE}/lib/pkgconfig/bigreqsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
