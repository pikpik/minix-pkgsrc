# $NetBSD: buildlink3.mk,v 1.9 2010/07/15 21:35:10 asau Exp $

BUILDLINK_TREE+=	gcal

.if !defined(GCAL_BUILDLINK3_MK)
GCAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcal+=	gcal>=3.6
BUILDLINK_ABI_DEPENDS.gcal?=	gcal>=3.6
BUILDLINK_PKGSRCDIR.gcal?=	../../time/gcal

.endif # GCAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcal
