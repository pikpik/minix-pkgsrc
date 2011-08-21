# $NetBSD$

BUILTIN_PKG:=	fontconfig
PKGCONFIG_FILE.fontconfig=	${X11BASE}/lib/pkgconfig/fontconfig.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
