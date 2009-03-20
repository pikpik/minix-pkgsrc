# $NetBSD: buildlink3.mk,v 1.6 2007/02/18 18:31:00 adrianp Exp $

BUILDLINK_TREE+=	libnet11

.if !defined(LIBNET11_BUILDLINK3_MK)
LIBNET11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet11+=	libnet11>=1.1.2.1
BUILDLINK_PKGSRCDIR.libnet11?=		../../devel/libnet11

BUILDLINK_INCDIRS.libnet11+=		include/libnet11
BUILDLINK_LIBDIRS.libnet11+=		lib/libnet11
BUILDLINK_CPPFLAGS.libnet11+=		-lnet
.endif # LIBNET11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnet11
