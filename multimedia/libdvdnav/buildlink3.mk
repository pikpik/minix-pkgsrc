# $NetBSD: buildlink3.mk,v 1.8 2009/01/14 22:36:11 jmcneill Exp $

BUILDLINK_TREE+=	libdvdnav

.if !defined(LIBDVDNAV_BUILDLINK3_MK)
LIBDVDNAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdnav+=	libdvdnav>=4.1.3
BUILDLINK_ABI_DEPENDS.libdvdnav+=	libdvdnav>=4.1.3
BUILDLINK_PKGSRCDIR.libdvdnav?=	../../multimedia/libdvdnav

.include "../../multimedia/libdvdread/buildlink3.mk"
.endif # LIBDVDNAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdnav
