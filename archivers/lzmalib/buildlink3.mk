# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/04 12:07:15 obache Exp $

BUILDLINK_TREE+=	lzmalib

.if !defined(LZMALIB_BUILDLINK3_MK)
LZMALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lzmalib+=	lzmalib>=0.0.1
BUILDLINK_PKGSRCDIR.lzmalib?=	../../archivers/lzmalib
.endif # LZMALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lzmalib
