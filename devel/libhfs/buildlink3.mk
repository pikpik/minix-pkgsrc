# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_TREE+=	libhfs

.if !defined(LIBHFS_BUILDLINK3_MK)
LIBHFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhfs+=	libhfs>=3.2.6nb1
BUILDLINK_PKGSRCDIR.libhfs?=	../../devel/libhfs
.endif # LIBHFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhfs
