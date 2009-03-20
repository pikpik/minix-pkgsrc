# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:37 jlam Exp $

BUILDLINK_TREE+=	libvorbis

.if !defined(LIBVORBIS_BUILDLINK3_MK)
LIBVORBIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvorbis+=	libvorbis>=1.0.1
BUILDLINK_ABI_DEPENDS.libvorbis+=	libvorbis>=1.1.0nb1
BUILDLINK_PKGSRCDIR.libvorbis?=	../../audio/libvorbis

.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBVORBIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvorbis
