# $NetBSD$

BUILTIN_PKG:=	libXres
PKGCONFIG_FILE.libXres=	${X11BASE}/lib/pkgconfig/xres.pc \
			${X11BASE}/lib/libXRes.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
