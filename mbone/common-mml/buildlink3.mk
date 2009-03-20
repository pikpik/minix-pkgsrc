# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	common-mml

.if !defined(COMMON_MML_BUILDLINK3_MK)
COMMON_MML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.common-mml+=	common-mml>=1.2.14
BUILDLINK_PKGSRCDIR.common-mml?=	../../mbone/common-mml
.endif # COMMON_MML_BUILDLINK3_MK

BUILDLINK_TREE+=	-common-mml
