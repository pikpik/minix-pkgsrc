# $NetBSD: buildlink3.mk,v 1.3 2006/11/25 00:09:19 reed Exp $

BUILDLINK_TREE+=	libXau

.if !defined(LIBXAU_BUILDLINK3_MK)
LIBXAU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXau+=	libXau>=1.0
BUILDLINK_PKGSRCDIR.libXau?=	../../x11/libXau

.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXau
