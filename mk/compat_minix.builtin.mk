# $NetBSD$

BUILTIN_PKG:=   compat_minix
PKGCONFIG_FILE.compat_minix=	/usr/netbsd/lib/compat_minix.pc

.include "../mk/buildlink3/pkgconfig-builtin.mk"
.include "../mk/buildlink3/bsd.builtin.mk"

