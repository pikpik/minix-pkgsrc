# $NetBSD: buildlink3.mk,v 1.6 2007/09/18 20:15:58 drochner Exp $

BUILDLINK_TREE+=	mpfr

.if !defined(MPFR_BUILDLINK3_MK)
MPFR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.0.3
BUILDLINK_PKGSRCDIR.mpfr?=	../../math/mpfr

.include "../../devel/gmp/buildlink3.mk"
.endif # MPFR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpfr
