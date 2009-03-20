# $NetBSD: buildlink3.mk,v 1.5 2008/04/22 18:06:09 tnn Exp $

BUILDLINK_TREE+=	libdnsres

.if !defined(LIBDNSRES_BUILDLINK3_MK)
LIBDNSRES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdnsres+=	libdnsres>=0.1a
BUILDLINK_ABI_DEPENDS.libdnsres?=	libdnsres>=0.1anb4
BUILDLINK_PKGSRCDIR.libdnsres?=	../../devel/libdnsres
.endif # LIBDNSRES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdnsres
