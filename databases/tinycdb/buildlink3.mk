# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_TREE+=	tinycdb

.if !defined(TINYCDB_BUILDLINK3_MK)
TINYCDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinycdb+=	tinycdb>=0.75
BUILDLINK_DEPMETHOD.tinycdb?=	build
BUILDLINK_PKGSRCDIR.tinycdb?=	../../databases/tinycdb
.endif # TINYCDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinycdb
