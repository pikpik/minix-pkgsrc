# $NetBSD: buildlink3.mk,v 1.23 2006/07/08 23:10:49 jlam Exp $

BUILDLINK_TREE+=	zlib

.if !defined(ZLIB_BUILDLINK3_MK)
ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.1.4nb1
BUILDLINK_ABI_DEPENDS.zlib+=	zlib>=1.2.3
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib
.endif # ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-zlib
