# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_TREE+=	libextractor

.if !defined(LIBEXTRACTOR_BUILDLINK3_MK)
LIBEXTRACTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libextractor+=	libextractor>=0.3.10
BUILDLINK_ABI_DEPENDS.libextractor+=	libextractor>=0.5.3nb3
BUILDLINK_PKGSRCDIR.libextractor?=	../../devel/libextractor
.endif # LIBEXTRACTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libextractor
