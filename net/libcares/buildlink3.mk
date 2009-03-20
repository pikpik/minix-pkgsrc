# $NetBSD: buildlink3.mk,v 1.6 2006/07/18 22:38:18 adrianp Exp $

BUILDLINK_TREE+=	libcares

.if !defined(LIBCARES_BUILDLINK3_MK)
LIBCARES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcares+=	libcares>=1.3.0nb1
BUILDLINK_PKGSRCDIR.libcares?=	../../net/libcares
.endif # LIBCARES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcares
