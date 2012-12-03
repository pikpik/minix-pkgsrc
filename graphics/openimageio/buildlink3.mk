# $NetBSD$

BUILDLINK_TREE+=	openimageio

.if !defined(OPENIMAGEIO_BUILDLINK3_MK)
OPENIMAGEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openimageio+=	openimageio>=1.1.1
BUILDLINK_PKGSRCDIR.openimageio?=	../../graphics/openimageio

.endif	# OPENIMAGEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-openimageio
