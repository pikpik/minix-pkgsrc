# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	R

.if !defined(R_BUILDLINK3_MK)
R_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R+=	R>=1.7.0
BUILDLINK_ABI_DEPENDS.R+=	R>=2.2.1nb2
BUILDLINK_PKGSRCDIR.R?=	../../math/R
.endif # R_BUILDLINK3_MK

BUILDLINK_TREE+=	-R
