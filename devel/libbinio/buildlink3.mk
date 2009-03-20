# $NetBSD: buildlink3.mk,v 1.2 2008/06/19 16:30:45 joerg Exp $

BUILDLINK_TREE+=	libbinio

.if !defined(LIBBINIO_BUILDLINK3_MK)
LIBBINIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbinio+=	libbinio>=1.4
BUILDLINK_PKGSRCDIR.libbinio?=		../../devel/libbinio
.endif # LIBBINIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbinio
