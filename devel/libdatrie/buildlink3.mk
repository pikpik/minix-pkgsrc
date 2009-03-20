# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/11 02:11:24 obache Exp $

BUILDLINK_TREE+=	libdatrie

.if !defined(LIBDATRIE_BUILDLINK3_MK)
LIBDATRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdatrie+=	libdatrie>=0.1.3
BUILDLINK_PKGSRCDIR.libdatrie?=	../../devel/libdatrie
.endif # LIBDATRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdatrie
