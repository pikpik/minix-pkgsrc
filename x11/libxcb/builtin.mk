# $NetBSD$

BUILTIN_PKG:=	libxcb
PKGCONFIG_FILE.libxcb=	${X11BASE}/lib/pkgconfig/xcb-proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
