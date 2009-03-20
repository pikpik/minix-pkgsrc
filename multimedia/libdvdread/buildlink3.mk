# $NetBSD: buildlink3.mk,v 1.9 2009/01/14 22:28:05 jmcneill Exp $

BUILDLINK_TREE+=	libdvdread

.if !defined(LIBDVDREAD_BUILDLINK3_MK)
LIBDVDREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdread+=	libdvdread>=4.1.3
BUILDLINK_ABI_DEPENDS.libdvdread+=	libdvdread>=4.1.3
BUILDLINK_PKGSRCDIR.libdvdread?=	../../multimedia/libdvdread
.endif # LIBDVDREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdread
