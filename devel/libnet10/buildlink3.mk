# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/18 18:36:21 adrianp Exp $

BUILDLINK_TREE+=	libnet10

.if !defined(LIBNET10_BUILDLINK3_MK)
LIBNET10_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet10+=	libnet10>=1.0.2a
BUILDLINK_PKGSRCDIR.libnet10?=		../../devel/libnet10

BUILDLINK_INCDIRS.libnet10+=		include/libnet10
BUILDLINK_LIBDIRS.libnet10+=		lib/libnet10
.endif # LIBNET10_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnet10
