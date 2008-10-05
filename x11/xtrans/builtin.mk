# $NetBSD$

BUILTIN_PKG:=	xtrans
PKGCONFIG_FILE.xtrans=	${X11BASE}/lib/pkgconfig/xtrans.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
