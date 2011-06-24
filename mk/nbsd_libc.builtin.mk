# $NetBSD$

BUILTIN_PKG:=   nbsd_libc
PKGCONFIG_FILE.minlib=	/usr/netbsd/lib/libc.pc

.include "../mk/buildlink3/pkgconfig-builtin.mk"
.include "../mk/buildlink3/bsd.builtin.mk"
