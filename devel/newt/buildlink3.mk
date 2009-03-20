# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:47 jlam Exp $

BUILDLINK_TREE+=	newt

.if !defined(NEWT_BUILDLINK3_MK)
NEWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.newt+=	newt>=0.51.6
BUILDLINK_ABI_DEPENDS.newt?=	newt>=0.51.6nb2
BUILDLINK_PKGSRCDIR.newt?=	../../devel/newt

.include "../../devel/libslang/buildlink3.mk"
.endif # NEWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-newt
