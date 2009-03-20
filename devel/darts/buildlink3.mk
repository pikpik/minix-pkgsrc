# $NetBSD: buildlink3.mk,v 1.8 2008/08/03 15:21:56 taca Exp $

BUILDLINK_TREE+=	darts

.if !defined(DARTS_BUILDLINK3_MK)
DARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.darts+=	darts>=0.32
BUILDLINK_PKGSRCDIR.darts?=	../../devel/darts
BUILDLINK_DEPMETHOD.darts?=	build
.endif # DARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-darts
