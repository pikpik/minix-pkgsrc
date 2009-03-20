# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:51 jlam Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=6b
BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=6bnb2
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
