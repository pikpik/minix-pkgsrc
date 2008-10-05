# $NetBSD$

BUILTIN_PKG:=	libfontenc
PKGCONFIG_FILE.libfontenc=	${X11BASE}/lib/pkgconfig/fontenc.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
