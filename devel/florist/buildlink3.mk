# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_TREE+=	florist

.if !defined(FLORIST_BUILDLINK3_MK)
FLORIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.florist+=	florist>=3.15p
BUILDLINK_ABI_DEPENDS.florist?=	florist>=3.15pnb2
BUILDLINK_PKGSRCDIR.florist?=	../../devel/florist
.endif # FLORIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-florist
