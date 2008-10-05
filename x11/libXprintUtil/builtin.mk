# $NetBSD$

BUILTIN_PKG:=	libXprintUtil
PKGCONFIG_FILE.libXprintUtil=	${X11BASE}/lib/pkgconfig/xprintutil.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
