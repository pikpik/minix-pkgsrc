# $NetBSD: buildlink3.mk,v 1.10 2007/02/02 19:17:31 joerg Exp $

BUILDLINK_TREE+=	libgii

.if !defined(LIBGII_BUILDLINK3_MK)
LIBGII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgii+=	libgii>=0.9.0
BUILDLINK_ABI_DEPENDS.libgii?=	libgii>=0.9.1nb1
BUILDLINK_PKGSRCDIR.libgii?=	../../graphics/libgii

.include "../../x11/libX11/buildlink3.mk"
.endif # LIBGII_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgii
