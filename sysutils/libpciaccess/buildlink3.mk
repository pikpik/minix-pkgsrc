# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/30 20:58:11 bjs Exp $

BUILDLINK_TREE+=	libpciaccess

.if !defined(LIBPCIACCESS_BUILDLINK3_MK)
LIBPCIACCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpciaccess+=	libpciaccess>=0.10.4
BUILDLINK_PKGSRCDIR.libpciaccess?=	../../sysutils/libpciaccess
.endif # LIBPCIACCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpciaccess
