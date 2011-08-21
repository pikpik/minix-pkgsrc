# $NetBSD$

BUILTIN_PKG:=	libXt
PKGCONFIG_FILE.libXt=	${X11BASE}/lib/pkgconfig/xt.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
