# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_TREE+=	gtl

.if !defined(GTL_BUILDLINK3_MK)
GTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtl+=		gtl>=1.2.0
BUILDLINK_PKGSRCDIR.gtl?=	../../devel/gtl
.endif # GTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtl
