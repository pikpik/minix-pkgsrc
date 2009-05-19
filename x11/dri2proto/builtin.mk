# $NetBSD$

BUILTIN_PKG:=	dri2proto
PKGCONFIG_FILE.dri2proto=	${X11BASE}/lib/pkgconfig/dri2proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
