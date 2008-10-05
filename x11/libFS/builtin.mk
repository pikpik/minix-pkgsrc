# $NetBSD$

BUILTIN_PKG:=	libFS
PKGCONFIG_FILE.libFS=	${X11BASE}/lib/pkgconfig/libfs.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
