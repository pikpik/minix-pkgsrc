# $NetBSD$

BUILTIN_PKG:=	libXtst
PKGCONFIG_FILE.libXtst=	${X11BASE}/lib/pkgconfig/xtst.pc \
				${X11BASE}/lib/libXtst.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
