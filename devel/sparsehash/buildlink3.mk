# $NetBSD: buildlink3.mk,v 1.12 2012/03/03 00:11:52 wiz Exp $

BUILDLINK_TREE+=	sparsehash

.if !defined(SPARSEHASH_BUILDLINK3_MK)
SPARSEHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sparsehash+=	sparsehash>=2.0.2
BUILDLINK_ABI_DEPENDS.sparsehash+=	sparsehash>=2.0.2
BUILDLINK_PKGSRCDIR.sparsehash?=	../../devel/sparsehash
.endif # SPARSEHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-sparsehash
