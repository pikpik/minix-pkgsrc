# $NetBSD: buildlink3.mk,v 1.8 2007/12/01 04:17:50 rillig Exp $

BUILDLINK_TREE+=	cryptopp

.if !defined(CRYPTOPP_BUILDLINK3_MK)
CRYPTOPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cryptopp+=	cryptopp>=5.1
BUILDLINK_DEPMETHOD.cryptopp?=	build
BUILDLINK_ABI_DEPENDS.cryptopp?=	cryptopp>=5.2.1nb1
BUILDLINK_PKGSRCDIR.cryptopp?=	../../security/crypto++
.endif # CRYPTOPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-cryptopp
