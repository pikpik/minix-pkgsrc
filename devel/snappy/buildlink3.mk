# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:17 joerg Exp $

BUILDLINK_TREE+=	snappy

.if !defined(SNAPPY_BUILDLINK3_MK)
SNAPPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.snappy+=	snappy>=1.0.5
BUILDLINK_ABI_DEPENDS.snappy+=	snappy>=1.0.5
BUILDLINK_PKGSRCDIR.snappy?=	../../devel/snappy
.endif # SNAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-snappy
