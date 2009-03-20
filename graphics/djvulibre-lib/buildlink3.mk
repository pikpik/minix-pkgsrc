# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/08/30 17:03:28 drochner Exp $

BUILDLINK_TREE+=	djvulibre-lib

.if !defined(DJVULIBRE_LIB_BUILDLINK3_MK)
DJVULIBRE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djvulibre-lib+=	djvulibre-lib>=3.5.17
BUILDLINK_PKGSRCDIR.djvulibre-lib?=	../../graphics/djvulibre-lib
.endif # DJVULIBRE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-djvulibre-lib
