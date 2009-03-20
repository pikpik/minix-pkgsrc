# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_TREE+=	ja-vflib-lib

.if !defined(JA_VFLIB_LIB_BUILDLINK3_MK)
JA_VFLIB_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-vflib-lib+=	ja-vflib-lib>=2.24.2
BUILDLINK_ABI_DEPENDS.ja-vflib-lib+=	ja-vflib-lib>=2.24.2nb2
BUILDLINK_PKGSRCDIR.ja-vflib-lib?=	../../print/ja-vflib-lib

.include "../../graphics/freetype-lib/buildlink3.mk"
.endif # JA_VFLIB_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-vflib-lib
