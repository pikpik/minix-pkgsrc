# $NetBSD$

BUILDLINK_TREE+=	openjpeg

.if !defined(OPENJPEG_BUILDLINK3_MK)
OPENJPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=1.3
BUILDLINK_PKGSRCDIR.openjpeg?=	../../graphics/openjpeg
.endif	# OPENJPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjpeg
