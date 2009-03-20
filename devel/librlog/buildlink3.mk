# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/18 14:18:18 xtraeme Exp $

BUILDLINK_TREE+=	librlog

.if !defined(LIBRLOG_BUILDLINK3_MK)
LIBRLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librlog+=	librlog>=1.3.7
BUILDLINK_PKGSRCDIR.librlog?=	../../devel/librlog
.endif # LIBRLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librlog
