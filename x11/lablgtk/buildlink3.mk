# $NetBSD: buildlink3.mk,v 1.26 2013/02/06 23:21:28 jperkin Exp $

BUILDLINK_TREE+=	lablgtk

.if !defined(LABLGTK_BUILDLINK3_MK)
LABLGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lablgtk+=	lablgtk>=2.6.0nb3
BUILDLINK_ABI_DEPENDS.lablgtk+=	lablgtk>=2.16.0nb8
BUILDLINK_PKGSRCDIR.lablgtk?=	../../x11/lablgtk

# gnome-panel must be exposed if and only if we built with it
pkgbase := lablgtk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.lablgtk:Mgnomecanvas)
.  include "../../x11/gnome-panel/buildlink3.mk"
.endif

.endif # LABLGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lablgtk
