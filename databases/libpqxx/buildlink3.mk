# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_TREE+=	libpqxx

.if !defined(LIBPQXX_BUILDLINK3_MK)
LIBPQXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpqxx+=	libpqxx>=2.5.0
BUILDLINK_ABI_DEPENDS.libpqxx?=	libpqxx>=2.5.4nb1
BUILDLINK_PKGSRCDIR.libpqxx?=	../../databases/libpqxx
.endif # LIBPQXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpqxx
