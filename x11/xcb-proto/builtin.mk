# $NetBSD$

BUILTIN_PKG:=	xcb-proto
PKGCONFIG_FILE.xcb-proto=	${X11BASE}/lib/pkgconfig/xcb-proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
