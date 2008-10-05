# $NetBSD$

BUILTIN_PKG:=	evieext
PKGCONFIG_FILE.evieext=	${X11BASE}/lib/pkgconfig/evieproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
