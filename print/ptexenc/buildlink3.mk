# $NetBSD$

BUILDLINK_TREE+=	ptexenc

.if !defined(PTEXENC_BUILDLINK3_MK)
PTEXENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ptexenc+=	ptexenc>=1.1.1
BUILDLINK_PKGSRCDIR.ptexenc?=	../../print/ptexenc

.include "../../print/kpathsea/buildlink3.mk"
.endif	# PTEXENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ptexenc
