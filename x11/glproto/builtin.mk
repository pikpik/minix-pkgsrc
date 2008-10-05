# $NetBSD$

BUILTIN_PKG:=	glproto
PKGCONFIG_FILE.glproto=	${X11BASE}/lib/pkgconfig/glproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
