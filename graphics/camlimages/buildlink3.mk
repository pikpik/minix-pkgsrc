# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:50 jlam Exp $

BUILDLINK_TREE+=	camlimages

.if !defined(CAMLIMAGES_BUILDLINK3_MK)
CAMLIMAGES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlimages+=	camlimages>=2.2.0
BUILDLINK_ABI_DEPENDS.camlimages?=	camlimages>=2.2.0nb1
BUILDLINK_PKGSRCDIR.camlimages?=	../../graphics/camlimages
.endif # CAMLIMAGES_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlimages
