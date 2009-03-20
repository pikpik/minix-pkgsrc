# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	adns

.if !defined(ADNS_BUILDLINK3_MK)
ADNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adns+=	adns>=1.0
BUILDLINK_ABI_DEPENDS.adns+=	adns>=1.1nb2
BUILDLINK_PKGSRCDIR.adns?=	../../net/adns
.endif # ADNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adns
