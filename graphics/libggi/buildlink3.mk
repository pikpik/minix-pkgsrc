# $NetBSD: buildlink3.mk,v 1.11 2007/02/04 15:26:34 joerg Exp $

BUILDLINK_TREE+=	libggi

.if !defined(LIBGGI_BUILDLINK3_MK)
LIBGGI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggi+=	libggi>=2.1.0
BUILDLINK_ABI_DEPENDS.libggi?=	libggi>=2.1.1nb1
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif # LIBGGI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libggi
