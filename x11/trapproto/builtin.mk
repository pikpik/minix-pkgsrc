# $NetBSD$

BUILTIN_PKG:=	trapproto
PKGCONFIG_FILE.trapproto=	${X11BASE}/lib/pkgconfig/trapproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
