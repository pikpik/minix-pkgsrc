# $NetBSD$

BUILTIN_PKG:=	libXfont
PKGCONFIG_FILE.libXfont=	${X11BASE}/lib/pkgconfig/xfont.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
