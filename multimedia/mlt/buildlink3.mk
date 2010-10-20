# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:03 joerg Exp $

BUILDLINK_TREE+=	mlt

.if !defined(MLT_BUILDLINK3_MK)
MLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlt+=	mlt>=0.5.10
BUILDLINK_ABI_DEPENDS.mlt+=	mlt>=0.5.10
BUILDLINK_PKGSRCDIR.mlt?=	../../multimedia/mlt
.endif # MLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlt
