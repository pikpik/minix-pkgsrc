# $NetBSD$

BUILTIN_PKG:=	libXTrap
PKGCONFIG_FILE.libXTrap=	${X11BASE}/lib/pkgconfig/xtrap.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
