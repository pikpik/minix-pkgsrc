# $NetBSD$

BUILTIN_PKG:=	freetype2
PKGCONFIG_FILE.freetype2=	${X11BASE}/lib/pkgconfig/freetype2.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
