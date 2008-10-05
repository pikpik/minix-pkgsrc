# $NetBSD$

BUILTIN_PKG:=	fontcacheproto
PKGCONFIG_FILE.fontcacheproto=	${X11BASE}/lib/pkgconfig/fontcacheproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
