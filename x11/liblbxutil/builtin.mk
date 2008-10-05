# $NetBSD$

BUILTIN_PKG:=	liblbxutil
PKGCONFIG_FILE.liblbxutil=	${X11BASE}/lib/pkgconfig/lbxutil.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
