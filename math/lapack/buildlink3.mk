# $NetBSD: buildlink3.mk,v 1.8 2007/12/10 17:50:31 adam Exp $

BUILDLINK_TREE+=	lapack

.if !defined(LAPACK_BUILDLINK3_MK)
LAPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapack+=	lapack>=3.1.1
BUILDLINK_ABI_DEPENDS.lapack+=	lapack>=3.1.1
BUILDLINK_PKGSRCDIR.lapack?=	../../math/lapack
.endif # LAPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapack
