# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:46 joerg Exp $

BUILDLINK_TREE+=	libchewing02

.if !defined(LIBCHEWING02_BUILDLINK3_MK)
LIBCHEWING02_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing02+=	libchewing>=0.2.7
BUILDLINK_API_DEPENDS.libchewing02+=	libchewing<0.3.0
BUILDLINK_ABI_DEPENDS.libchewing02+=	libchewing>=0.2.7
BUILDLINK_ABI_DEPENDS.libchewing02+=	libchewing<0.3.0
BUILDLINK_PKGSRCDIR.libchewing02?=	../../inputmethod/libchewing02
.endif # LIBCHEWING02_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing02
