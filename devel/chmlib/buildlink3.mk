# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_TREE+=	chmlib

.if !defined(CHMLIB_BUILDLINK3_MK)
CHMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chmlib+=	chmlib>=0.31
BUILDLINK_ABI_DEPENDS.chmlib+=	chmlib>=0.37.4nb2
BUILDLINK_PKGSRCDIR.chmlib?=	../../devel/chmlib
.endif # CHMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-chmlib
