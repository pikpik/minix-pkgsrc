# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/08/10 21:21:01 gdt Exp $

BUILDLINK_TREE+=	guile-cairo

.if !defined(GUILE_CAIRO_BUILDLINK3_MK)
GUILE_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile-cairo+=	guile-cairo>=1.4.0
BUILDLINK_PKGSRCDIR.guile-cairo?=	../../graphics/guile-cairo
.endif # GUILE_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile-cairo
