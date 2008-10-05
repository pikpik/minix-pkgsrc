# $NetBSD$

BUILTIN_PKG:=	recordproto
PKGCONFIG_FILE.recordproto=	${X11BASE}/lib/pkgconfig/recordproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
