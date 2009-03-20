# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	libcdio

.if !defined(LIBCDIO_BUILDLINK3_MK)
LIBCDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio+=	libcdio>=0.65
BUILDLINK_ABI_DEPENDS.libcdio+=	libcdio>=0.76nb1
BUILDLINK_PKGSRCDIR.libcdio?=	../../misc/libcdio
.endif # LIBCDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio
