# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_TREE+=	sdbm

.if !defined(SDBM_BUILDLINK3_MK)
SDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sdbm+=	sdbm>=90.12.1
BUILDLINK_PKGSRCDIR.sdbm?=	../../databases/sdbm
.endif # SDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdbm
