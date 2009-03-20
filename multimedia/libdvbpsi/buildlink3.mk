# $NetBSD: buildlink3.mk,v 1.8 2009/02/27 22:38:16 wiz Exp $

BUILDLINK_TREE+=	libdvbpsi

.if !defined(LIBDVBPSI_BUILDLINK3_MK)
LIBDVBPSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvbpsi+=	libdvbpsi>=0.1.3
BUILDLINK_ABI_DEPENDS.libdvbpsi+=	libdvbpsi>=0.1.6
BUILDLINK_PKGSRCDIR.libdvbpsi?=	../../multimedia/libdvbpsi
.endif # LIBDVBPSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvbpsi
