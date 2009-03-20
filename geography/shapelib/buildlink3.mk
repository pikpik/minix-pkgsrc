# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:50 jlam Exp $

BUILDLINK_TREE+=	shapelib

.if !defined(SHAPELIB_BUILDLINK3_MK)
SHAPELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shapelib+=	shapelib>=1.2.10
BUILDLINK_PKGSRCDIR.shapelib?=	../../geography/shapelib
.endif # SHAPELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-shapelib
