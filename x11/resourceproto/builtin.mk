# $NetBSD$

BUILTIN_PKG:=	resourceproto
PKGCONFIG_FILE.resourceproto=	${X11BASE}/lib/pkgconfig/resourceproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
