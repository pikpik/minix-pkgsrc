# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_TREE+=	libiberty

.if !defined(LIBIBERTY_BUILDLINK3_MK)
LIBIBERTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiberty+=	libiberty>=1.0nb1
BUILDLINK_ABI_DEPENDS.libiberty?=	libiberty>=1.0nb2
BUILDLINK_PKGSRCDIR.libiberty?=	../../devel/libiberty
BUILDLINK_DEPMETHOD.libiberty?= build
.endif # LIBIBERTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiberty
