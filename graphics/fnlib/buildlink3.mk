# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:50 jlam Exp $

BUILDLINK_TREE+=	fnlib

.if !defined(FNLIB_BUILDLINK3_MK)
FNLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fnlib+=	fnlib>=0.5nb6
BUILDLINK_ABI_DEPENDS.fnlib+=	fnlib>=0.5nb10
BUILDLINK_PKGSRCDIR.fnlib?=	../../graphics/fnlib

.include "../../graphics/imlib/buildlink3.mk"
.endif # FNLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-fnlib
