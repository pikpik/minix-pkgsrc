# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:01 jlam Exp $

BUILDLINK_TREE+=	libdvdcss

.if !defined(LIBDVDCSS_BUILDLINK3_MK)
LIBDVDCSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdcss+=	libdvdcss>=1.2.4
BUILDLINK_ABI_DEPENDS.libdvdcss+=	libdvdcss>=1.2.8nb1
BUILDLINK_PKGSRCDIR.libdvdcss?=	../../multimedia/libdvdcss
.endif # LIBDVDCSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdcss
