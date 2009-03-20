# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_TREE+=	pslib

.if !defined(PSLIB_BUILDLINK3_MK)
PSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pslib+=	pslib>=0.2.6
BUILDLINK_ABI_DEPENDS.pslib?=	pslib>=0.2.6nb3
BUILDLINK_PKGSRCDIR.pslib?=	../../print/pslib
.endif # PSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pslib
