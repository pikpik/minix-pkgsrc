# $NetBSD$

BUILTIN_PKG:=	xcmiscproto
PKGCONFIG_FILE.xcmiscproto=	${X11BASE}/lib/pkgconfig/xcmiscproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
