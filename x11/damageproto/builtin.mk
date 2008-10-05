# $NetBSD$

BUILTIN_PKG:=	damageproto
PKGCONFIG_FILE.damageproto=	${X11BASE}/lib/pkgconfig/damageproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
