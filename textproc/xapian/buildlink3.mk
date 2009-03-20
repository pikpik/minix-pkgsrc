# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/07/26 23:35:05 schmonz Exp $

BUILDLINK_TREE+=	xapian

.if !defined(XAPIAN_BUILDLINK3_MK)
XAPIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.0.7
BUILDLINK_PKGSRCDIR.xapian?=	../../textproc/xapian
.endif # XAPIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapian
