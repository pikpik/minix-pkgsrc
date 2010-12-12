# $NetBSD$

BUILDLINK_TREE+=	libjpeg-turbo

.if !defined(LIBJPEG_TURBO_BUILDLINK3_MK)
LIBJPEG_TURBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjpeg-turbo+=	libjpeg-turbo>=1.0.1
BUILDLINK_PKGSRCDIR.libjpeg-turbo?=	../../graphics/libjpeg-turbo
.endif	# LIBJPEG_TURBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjpeg-turbo
