# $NetBSD$

BUILTIN_PKG:=	libdrm
PKGCONFIG_FILE.libdrm=	${X11BASE}/lib/pkgconfig/libdrm.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
