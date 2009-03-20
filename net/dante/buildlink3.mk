# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	dante

.if !defined(DANTE_BUILDLINK3_MK)
DANTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dante+=	dante>=1.1.13
BUILDLINK_ABI_DEPENDS.dante+=	dante>=1.1.14nb1
BUILDLINK_PKGSRCDIR.dante?=	../../net/dante
.endif # DANTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-dante
