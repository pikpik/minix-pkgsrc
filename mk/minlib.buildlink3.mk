# $NetBSD$

BUILDLINK_TREE+=        minlib

.if !defined(MINLIB_BUILDLINK3_MK)
MINLIB_BUILDLINK3_MK:=

CHECK_BUILTIN.minlib:= yes
.include "minlib.builtin.mk"
CHECK_BUILTIN.minlib:= no

BUILDLINK_API_DEPENDS.minlib+= minlib>=1.0

BUILDLINK_LIBNAME.minlib=	minlib
BUILDLINK_PREFIX.minlib=	/usr/netbsd
BUILDLINK_FILES.minlib=		lib/libminlib.a

.endif

BUILDLINK_TREE+=        -minlib
