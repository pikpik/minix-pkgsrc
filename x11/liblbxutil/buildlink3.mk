# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/14 15:27:49 joerg Exp $

BUILDLINK_TREE+=	liblbxutil

.if !defined(LIBLBXUTIL_BUILDLINK3_MK)
LIBLBXUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblbxutil+=	liblbxutil>=1.0.0
BUILDLINK_PKGSRCDIR.liblbxutil?=	../../x11/liblbxutil

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBLBXUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblbxutil
