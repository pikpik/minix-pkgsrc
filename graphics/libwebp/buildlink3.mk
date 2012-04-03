# $NetBSD$

BUILDLINK_TREE+=	libwebp

.if !defined(LIBWEBP_BUILDLINK3_MK)
LIBWEBP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=0.1.3
BUILDLINK_PKGSRCDIR.libwebp?=	../../graphics/libwebp

.endif	# LIBWEBP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebp
