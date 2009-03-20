# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:48 jlam Exp $

BUILDLINK_TREE+=	rx

.if !defined(RX_BUILDLINK3_MK)
RX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rx+=		rx>=1.5
BUILDLINK_PKGSRCDIR.rx?=	../../devel/rx
.endif # RX_BUILDLINK3_MK

BUILDLINK_TREE+=	-rx
