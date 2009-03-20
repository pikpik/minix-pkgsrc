# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_TREE+=	dbh

.if !defined(DBH_BUILDLINK3_MK)
DBH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbh+=		dbh>=1.0.22
BUILDLINK_PKGSRCDIR.dbh?=	../../databases/dbh
.endif # DBH_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbh
