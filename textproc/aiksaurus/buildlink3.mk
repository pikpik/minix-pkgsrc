# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_TREE+=	aiksaurus

.if !defined(AIKSAURUS_BUILDLINK3_MK)
AIKSAURUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aiksaurus+=	aiksaurus>=1.2.1
BUILDLINK_PKGSRCDIR.aiksaurus?=	../../textproc/aiksaurus
.endif # AIKSAURUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-aiksaurus
