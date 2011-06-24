# $NetBSD$

BUILTIN_PKG:=   minlib
PKGCONFIG_FILE.minlib=	/usr/netbsd/lib/minlib.pc

.include "../mk/buildlink3/pkgconfig-builtin.mk"
.include "../mk/buildlink3/bsd.builtin.mk"

