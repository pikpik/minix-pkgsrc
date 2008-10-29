# $NetBSD$

BUILTIN_PKG:=	libXv
PKGCONFIG_FILE.libXv=	${X11BASE}/lib/pkgconfig/xv.pc \
				${X11BASE}/lib/libXv.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
