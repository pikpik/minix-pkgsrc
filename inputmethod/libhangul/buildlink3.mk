# $NetBSD: buildlink3.mk,v 1.2 2007/05/09 17:29:39 minskim Exp $

BUILDLINK_TREE+=	libhangul

.if !defined(LIBHANGUL_BUILDLINK3_MK)
LIBHANGUL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.4
BUILDLINK_PKGSRCDIR.libhangul?=	../../inputmethod/libhangul
.endif # LIBHANGUL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhangul
