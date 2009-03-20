# $NetBSD: buildlink3.mk,v 1.10 2008/12/28 07:56:38 adam Exp $

BUILDLINK_TREE+=	gnustep-preferences

.if !defined(GNUSTEP_PREFERENCES_BUILDLINK3_MK)
GNUSTEP_PREFERENCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0
BUILDLINK_ABI_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0nb16
BUILDLINK_PKGSRCDIR.gnustep-preferences?=	../../x11/gnustep-preferences

.include "../../x11/gnustep-back/buildlink3.mk"
.endif # GNUSTEP_PREFERENCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-preferences
