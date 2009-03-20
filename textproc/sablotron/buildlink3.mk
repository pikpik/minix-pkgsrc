# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_TREE+=	sablotron

.if !defined(SABLOTRON_BUILDLINK3_MK)
SABLOTRON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sablotron+=	sablotron>=1.0
BUILDLINK_ABI_DEPENDS.sablotron+=	sablotron>=1.0.2nb2
BUILDLINK_PKGSRCDIR.sablotron?=	../../textproc/sablotron

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # SABLOTRON_BUILDLINK3_MK

BUILDLINK_TREE+=	-sablotron
