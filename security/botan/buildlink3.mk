# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:06 jlam Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.4.11
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
