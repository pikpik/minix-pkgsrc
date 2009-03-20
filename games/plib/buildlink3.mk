# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:49 jlam Exp $

BUILDLINK_TREE+=	plib

.if !defined(PLIB_BUILDLINK3_MK)
PLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plib+=	plib>=1.6.0
BUILDLINK_ABI_DEPENDS.plib?=	plib>=1.6.0nb3
BUILDLINK_PKGSRCDIR.plib?=	../../games/plib
BUILDLINK_DEPMETHOD.plib?=	build

.include "../../graphics/Mesa/buildlink3.mk"
.endif # PLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-plib
