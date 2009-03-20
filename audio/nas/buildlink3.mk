# $NetBSD: buildlink3.mk,v 1.9 2006/07/12 17:21:52 rillig Exp $

BUILDLINK_TREE+=	nas

.if !defined(NAS_BUILDLINK3_MK)
NAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nas+=	nas>=1.4.2
BUILDLINK_ABI_DEPENDS.nas+=	nas>=1.7bnb2
BUILDLINK_PKGSRCDIR.nas?=	../../audio/nas
.endif # NAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nas
