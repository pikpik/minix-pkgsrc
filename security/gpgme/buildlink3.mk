# $NetBSD: buildlink3.mk,v 1.16 2006/07/19 23:01:49 wiz Exp $

BUILDLINK_TREE+=	gpgme

.if !defined(GPGME_BUILDLINK3_MK)
GPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_ABI_DEPENDS.gpgme+=	gpgme>=1.0.3nb1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../devel/librfuncs/buildlink3.mk"
.endif # GPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgme
