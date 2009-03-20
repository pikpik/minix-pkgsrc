# $NetBSD: buildlink3.mk,v 1.3 2008/10/05 21:36:33 cube Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	libXdamage

.if !defined(LIBXDAMAGE_BUILDLINK3_MK)
LIBXDAMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXdamage+=	libXdamage>=1.0.3
BUILDLINK_PKGSRCDIR.libXdamage?=	../../x11/libXdamage

.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXDAMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXdamage
