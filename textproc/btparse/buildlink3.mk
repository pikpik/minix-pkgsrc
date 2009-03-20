# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_TREE+=	btparse

.if !defined(BTPARSE_BUILDLINK3_MK)
BTPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.btparse+=	btparse>=0.34
BUILDLINK_PKGSRCDIR.btparse?=	../../textproc/btparse
.endif # BTPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-btparse
