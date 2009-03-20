# $NetBSD: buildlink3.mk,v 1.7 2007/01/17 03:11:18 rillig Exp $

BUILDLINK_TREE+=	gnustep-objc-lf2

.if !defined(GNUSTEP_OBJC_LF2_BUILDLINK3_MK)
GNUSTEP_OBJC_LF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc-lf2+=	gnustep-objc-lf2>=2.95.3.88
BUILDLINK_ABI_DEPENDS.gnustep-objc-lf2?=	gnustep-objc-lf2>=2.95.3.88nb1
BUILDLINK_PKGSRCDIR.gnustep-objc-lf2?=	../../devel/gnustep-objc-lf2
BUILDLINK_FNAME_TRANSFORM.gnustep-objc-lf2?=	-e "s|Headers/objc_lf2/|Headers/objc/|g"
BUILDLINK_TRANSFORM+=	l:objc:objc_lf2

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # GNUSTEP_OBJC_LF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc-lf2
