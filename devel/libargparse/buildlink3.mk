# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_TREE+=	libargparse

.if !defined(LIBARGPARSE_BUILDLINK3_MK)
LIBARGPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libargparse+=	libargparse>=0.1.0000
BUILDLINK_ABI_DEPENDS.libargparse+=	libargparse>=0.1.0000nb1
BUILDLINK_PKGSRCDIR.libargparse?=	../../devel/libargparse
.endif # LIBARGPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libargparse
