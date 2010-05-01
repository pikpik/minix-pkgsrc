# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:05 joerg Exp $

BUILDLINK_TREE+=	libcassandra

.if !defined(LIBCASSANDRA_BUILDLINK3_MK)
LIBCASSANDRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcassandra+=	libcassandra>=20100501
BUILDLINK_ABI_DEPENDS.libcassandra?=	libcassandra>=20100501
BUILDLINK_PKGSRCDIR.libcassandra?=	../../databases/libcassandra
.endif # LIBCASSANDRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcassandra
