# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	libdnet

.if !defined(LIBDNET_BUILDLINK3_MK)
LIBDNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdnet+=	libdnet>=1.7
BUILDLINK_ABI_DEPENDS.libdnet?=	libdnet>=1.10nb1
BUILDLINK_PKGSRCDIR.libdnet?=	../../net/libdnet
.endif # LIBDNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdnet
