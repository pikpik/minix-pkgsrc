# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:11:08 jlam Exp $

BUILDLINK_TREE+=	rsaref

.if !defined(RSAREF_BUILDLINK3_MK)
RSAREF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rsaref+=	rsaref>=2.0p3
BUILDLINK_ABI_DEPENDS.rsaref+=	rsaref>=2.0p3nb1
BUILDLINK_PKGSRCDIR.rsaref?=	../../security/rsaref
.endif # RSAREF_BUILDLINK3_MK

BUILDLINK_TREE+=	-rsaref
