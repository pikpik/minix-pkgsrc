# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:42 joerg Exp $

BUILDLINK_TREE+=	libgii

.if !defined(LIBGII_BUILDLINK3_MK)
LIBGII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgii+=	libgii>=1.0.2
BUILDLINK_PKGSRCDIR.libgii?=	../../graphics/libgii

.include "../../x11/libX11/buildlink3.mk"
.endif # LIBGII_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgii
