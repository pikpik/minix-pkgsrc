# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_TREE+=	edb

.if !defined(EDB_BUILDLINK3_MK)
EDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edb+=	edb>=1.0.3nb3
BUILDLINK_ABI_DEPENDS.edb+=	edb>=1.0.3nb5
BUILDLINK_PKGSRCDIR.edb?=	../../databases/edb
.endif # EDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-edb
