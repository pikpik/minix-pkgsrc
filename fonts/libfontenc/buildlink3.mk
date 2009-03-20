# $NetBSD: buildlink3.mk,v 1.3 2007/06/30 03:06:58 joerg Exp $

BUILDLINK_TREE+=	libfontenc

.if !defined(LIBFONTENC_BUILDLINK3_MK)
LIBFONTENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfontenc+=	libfontenc>=0.99
BUILDLINK_PKGSRCDIR.libfontenc?=	../../fonts/libfontenc

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBFONTENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfontenc
