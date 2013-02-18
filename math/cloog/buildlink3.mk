# $NetBSD$

BUILDLINK_TREE+=	cloog

.if !defined(CLOOG_BUILDLINK3_MK)
CLOOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cloog+=	cloog>=0.18.0nb1
BUILDLINK_PKGSRCDIR.cloog?=	../../math/cloog

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.endif	# CLOOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-cloog
