# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/02/26 21:51:06 plunky Exp $

BUILDLINK_TREE+=	libfprint

.if !defined(LIBFPRINT_BUILDLINK3_MK)
LIBFPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfprint+=	libfprint>=0.0.6
BUILDLINK_ABI_DEPENDS.libfprint+=	libfprint>=0.0.6
BUILDLINK_PKGSRCDIR.libfprint?=		../../security/libfprint
.endif # LIBFPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfprint
