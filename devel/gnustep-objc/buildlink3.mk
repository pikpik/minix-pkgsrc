# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:14 joerg Exp $

BUILDLINK_TREE+=	gnustep-objc

.if !defined(GNUSTEP_OBJC_BUILDLINK3_MK)
GNUSTEP_OBJC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0
BUILDLINK_ABI_DEPENDS.gnustep-objc?=	gnustep-objc>=1.3.0nb1
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc

BUILDLINK_LDFLAGS.gnustep-objc+=	-lobjc -lpthread

PRINT_PLIST_AWK+=	/^@dirrm include\/objc$$/ { print "@comment in devel/gnustep-objc: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/objc$$/ { next; }

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # GNUSTEP_OBJC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc
