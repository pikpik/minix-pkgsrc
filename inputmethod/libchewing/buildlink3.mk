# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=		libchewing>=0.2.7
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.2.7
BUILDLINK_PKGSRCDIR.libchewing?=	../../inputmethod/libchewing
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing
