# $NetBSD$

BUILTIN_PKG:=	videoproto
PKGCONFIG_FILE.videoproto=	${X11BASE}/lib/pkgconfig/videoproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
