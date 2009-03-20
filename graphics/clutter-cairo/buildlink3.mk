# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/14 11:04:35 obache Exp $
#

BUILDLINK_TREE+=	clutter-cairo

.if !defined(CLUTTER_CAIRO_BUILDLINK3_MK)
CLUTTER_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-cairo+=	clutter-cairo>=0.8.0
BUILDLINK_PKGSRCDIR.clutter-cairo?=	../../graphics/clutter-cairo

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.endif # CLUTTER_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-cairo
