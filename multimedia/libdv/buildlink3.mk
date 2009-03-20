# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:01 jlam Exp $

BUILDLINK_TREE+=	libdv

.if !defined(LIBDV_BUILDLINK3_MK)
LIBDV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdv+=	libdv>=0.102
BUILDLINK_ABI_DEPENDS.libdv+=	libdv>=0.104nb2
BUILDLINK_PKGSRCDIR.libdv?=	../../multimedia/libdv
.endif # LIBDV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdv
