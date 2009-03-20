# $NetBSD: buildlink3.mk,v 1.2 2006/11/05 16:55:28 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../x11/Xfixes/buildlink3.mk"
.else

BUILDLINK_TREE+=	libXfixes

.if !defined(LIBXFIXES_BUILDLINK3_MK)
LIBXFIXES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfixes+=	libXfixes>=4.0.1
BUILDLINK_PKGSRCDIR.libXfixes?=	../../x11/libXfixes

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBXFIXES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfixes

.endif
