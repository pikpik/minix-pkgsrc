# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/02/26 18:12:55 minskim Exp $

BUILDLINK_TREE+=	evas

.if !defined(EVAS_BUILDLINK3_MK)
EVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas+=	evas>=0.9.9.050
BUILDLINK_PKGSRCDIR.evas?=	../../graphics/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # EVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas
