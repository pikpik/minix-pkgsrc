# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	libportlib

.if !defined(LIBPORTLIB_BUILDLINK3_MK)
LIBPORTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libportlib+=	libportlib>=1.01
BUILDLINK_PKGSRCDIR.libportlib?=	../../devel/libportlib
BUILDLINK_DEPMETHOD.libportlib?=	build
.endif # LIBPORTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libportlib
