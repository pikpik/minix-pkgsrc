# $NetBSD: buildlink3.mk,v 1.2 2008/12/17 16:52:35 joerg Exp $

BUILDLINK_TREE+=	libfirm

.if !defined(LIBFIRM_BUILDLINK3_MK)
LIBFIRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfirm+=	libfirm>=1.15.0
BUILDLINK_PKGSRCDIR.libfirm?=	../../devel/libfirm
.endif # LIBFIRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfirm
