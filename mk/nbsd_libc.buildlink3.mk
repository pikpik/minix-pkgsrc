# $NetBSD$

BUILDLINK_TREE+=        nbsd_libc

.if !defined(NBSD_LIBC_BUILDLINK3_MK)
NBSD_LIBC_BUILDLINK3_MK:=

CHECK_BUILTIN.nbsd_libc:= yes
.include "nbsd_libc.builtin.mk"
CHECK_BUILTIN.nbsd_libc:= no

BUILDLINK_API_DEPENDS.nbsd_libc+= nbsd_libc>=1.0

BUILDLINK_LIBNAME.nbsd_libc=	c
BUILDLINK_PREFIX.nbsd_libc=	/usr/netbsd
BUILDLINK_FILES.nbsd_libc=	lib/libc.a

.include "/usr/pkgsrc/mk/compat_minix.buildlink3.mk"
.include "/usr/pkgsrc/mk/minlib.buildlink3.mk"

.endif

BUILDLINK_TREE+=        -nbsd_libc
