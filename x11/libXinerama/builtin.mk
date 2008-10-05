# $NetBSD: builtin.mk,v 1.1 2007/12/16 23:08:05 tron Exp $

BUILTIN_PKG:=	libXinerama
PKGCONFIG_FILE.libXinerama=	${X11BASE}/lib/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
