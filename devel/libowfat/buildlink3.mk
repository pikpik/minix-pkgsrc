# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/06 23:48:49 wiz Exp $

BUILDLINK_TREE+=	libowfat

.if !defined(LIBOWFAT_BUILDLINK3_MK)
LIBOWFAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libowfat+=	libowfat>=0.26
BUILDLINK_PKGSRCDIR.libowfat?=		../../devel/libowfat
BUILDLINK_DEPMETHOD.libowfat?=		build
.endif # LIBOWFAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libowfat
