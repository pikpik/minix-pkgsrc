# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:10:41 jlam Exp $

BUILDLINK_TREE+=	boehm-gc

.if !defined(BOEHM_GC_BUILDLINK3_MK)
BOEHM_GC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=6.3nb1
BUILDLINK_ABI_DEPENDS.boehm-gc+=	boehm-gc>=6.6nb1
BUILDLINK_PKGSRCDIR.boehm-gc?=	../../devel/boehm-gc
.endif # BOEHM_GC_BUILDLINK3_MK

BUILDLINK_TREE+=	-boehm-gc
