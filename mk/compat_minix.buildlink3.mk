# $NetBSD$

BUILDLINK_TREE+=        compat_minix

.if !defined(COMPAT_MINIX_BUILDLINK3_MK)
COMPAT_MINIX_BUILDLINK3_MK:=

CHECK_BUILTIN.compat_minix:= yes
.include "compat_minix.builtin.mk"
CHECK_BUILTIN.compat_minix:= no

BUILDLINK_API_DEPENDS.compat_minix+= compat_minix>=1.0

BUILDLINK_LIBNAME.compat_minix=		compat_minix
BUILDLINK_PREFIX.compat_minix=		/usr/netbsd
BUILDLINK_FILES.compat_minix=		lib/libcompat_minix.a
.endif

BUILDLINK_TREE+=        -compat_minix

