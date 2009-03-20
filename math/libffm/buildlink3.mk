# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_TREE+=	libffm

.if !defined(LIBFFM_BUILDLINK3_MK)
LIBFFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffm+=	libffm>=0.28
BUILDLINK_ABI_DEPENDS.libffm?=	libffm>=0.28nb1
BUILDLINK_PKGSRCDIR.libffm?=	../../math/libffm
.endif # LIBFFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffm
