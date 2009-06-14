# $NetBSD: buildlink3.mk,v 1.15 2009/04/13 12:16:24 rh Exp $

BUILDLINK_TREE+=	gnustep-base

.if !defined(GNUSTEP_BASE_BUILDLINK3_MK)
GNUSTEP_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.18.0
BUILDLINK_ABI_DEPENDS.gnustep-base+=	gnustep-base>=1.18.0
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.endif # GNUSTEP_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-base
