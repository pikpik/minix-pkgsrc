# $NetBSD$

BUILTIN_PKG:=				xkeyboard-config
PKGCONFIG_FILE.xkeyboard-config=	${X11BASE}/lib/pkgconfig/xkeyboard-config.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
