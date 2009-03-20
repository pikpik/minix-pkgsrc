# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/10/13 02:31:56 epg Exp $

BUILDLINK_TREE+=	libdiscid

.if !defined(LIBDISCID_BUILDLINK3_MK)
LIBDISCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdiscid+=	libdiscid>=0.1.0
BUILDLINK_PKGSRCDIR.libdiscid?=	../../audio/libdiscid
.endif # LIBDISCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdiscid
