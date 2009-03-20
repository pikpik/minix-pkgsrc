# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_TREE+=	libpathan

.if !defined(LIBPATHAN_BUILDLINK3_MK)
LIBPATHAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpathan+=	libpathan>=1.2.2
BUILDLINK_ABI_DEPENDS.libpathan+=	libpathan>=1.2.2nb2
BUILDLINK_PKGSRCDIR.libpathan?=	../../textproc/libpathan

.include "../../textproc/xerces-c/buildlink3.mk"
.endif # LIBPATHAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpathan
