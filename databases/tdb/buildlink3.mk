# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_TREE+=	tdb

.if !defined(TDB_BUILDLINK3_MK)
TDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdb+=		tdb>=1.0.6
BUILDLINK_ABI_DEPENDS.tdb+=	tdb>=1.0.6nb2
BUILDLINK_PKGSRCDIR.tdb?=	../../databases/tdb
.endif # TDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdb
