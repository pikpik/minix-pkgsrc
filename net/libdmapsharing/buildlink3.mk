# $NetBSD$

BUILDLINK_TREE+=	libdmapsharing

.if !defined(LIBDMAPSHARING_BUILDLINK3_MK)
LIBDMAPSHARING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdmapsharing+=	libdmapsharing>=2.1.9
BUILDLINK_PKGSRCDIR.libdmapsharing?=	../../net/libdmapsharing

.endif	# LIBDMAPSHARING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdmapsharing
