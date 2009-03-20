# $NetBSD: buildlink3.mk,v 1.5 2008/03/03 12:31:09 drochner Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xrandr.pc)
.include "../../x11/liboldXrandr/buildlink3.mk"
.else

BUILDLINK_TREE+=	libXrandr

.if !defined(LIBXRANDR_BUILDLINK3_MK)
LIBXRANDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.1.2
BUILDLINK_PKGSRCDIR.libXrandr?=	../../x11/libXrandr

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.endif # LIBXRANDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXrandr

.endif
