# $NetBSD$

BUILDLINK_TREE+=	libva

.if !defined(LIBVA_BUILDLINK3_MK)
LIBVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libva+=	libva>=1.0.6
BUILDLINK_PKGSRCDIR.libva?=	../../multimedia/libva

.endif	# LIBVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libva
