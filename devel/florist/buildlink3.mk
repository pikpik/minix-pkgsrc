# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:21 dholland Exp $

BUILDLINK_TREE+=	florist

.if !defined(FLORIST_BUILDLINK3_MK)
FLORIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.florist+=	florist>=2012
BUILDLINK_ABI_DEPENDS.florist+=	florist>=2012
BUILDLINK_PKGSRCDIR.florist?=	../../devel/florist
.endif # FLORIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-florist
