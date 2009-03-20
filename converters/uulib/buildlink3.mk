# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_TREE+=	uulib

.if !defined(UULIB_BUILDLINK3_MK)
UULIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uulib+=	uulib>=0.5.20
BUILDLINK_ABI_DEPENDS.uulib+=	uulib>=0.5.20nb2
BUILDLINK_PKGSRCDIR.uulib?=	../../converters/uulib
.endif # UULIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-uulib
