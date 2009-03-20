# $NetBSD: buildlink3.mk,v 1.8 2007/05/22 14:04:33 reed Exp $

BUILDLINK_TREE+=	spread

.if !defined(SPREAD_BUILDLINK3_MK)
SPREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spread+=	spread>=3.17.1
BUILDLINK_PKGSRCDIR.spread?=	../../net/spread
BUILDLINK_INCDIRS.spread?=	include/spread
.endif # SPREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-spread
