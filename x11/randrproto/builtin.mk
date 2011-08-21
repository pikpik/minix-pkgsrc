# $NetBSD$

BUILTIN_PKG:=	randrproto
PKGCONFIG_FILE.randrproto=	${X11BASE}/lib/pkgconfig/randrproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
