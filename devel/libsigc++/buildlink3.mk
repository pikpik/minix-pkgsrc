# $NetBSD: buildlink3.mk,v 1.10 2007/09/21 12:59:53 wiz Exp $

BUILDLINK_TREE+=	libsigcpp

.if !defined(LIBSIGCPP_BUILDLINK3_MK)
LIBSIGCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.0.3
BUILDLINK_ABI_DEPENDS.libsigcpp+=	libsigc++>=2.0.17nb1
BUILDLINK_PKGSRCDIR.libsigcpp?=		../../devel/libsigc++
.endif # LIBSIGCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigcpp
