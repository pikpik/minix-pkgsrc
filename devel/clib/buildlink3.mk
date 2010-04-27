# $NetBSD: buildlink3.mk,v 1.24 2009/03/20 19:24:31 joerg Exp $

BUILDLINK_TREE+=	clib

.if !defined(CLIB_BUILDLINK3_MK)
CLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clib+=	clib>=0.2
BUILDLINK_ABI_DEPENDS.clib+=	clib>=0.2
BUILDLINK_PKGSRCDIR.clib?=	../../devel/clib
.endif # CLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-clib
