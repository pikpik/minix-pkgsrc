# $NetBSD: buildlink3.mk,v 1.18 2010/09/14 11:00:59 wiz Exp $

BUILDLINK_TREE+=	librsvg

.if !defined(LIBRSVG_BUILDLINK3_MK)
LIBRSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.12.6nb1
BUILDLINK_ABI_DEPENDS.librsvg+=		librsvg>=2.26.3nb2
BUILDLINK_PKGSRCDIR.librsvg?=		../../graphics/librsvg

.include "../../textproc/libcroco/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif # LIBRSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsvg
