# $NetBSD: buildlink3.mk,v 1.7 2007/02/01 10:21:57 drochner Exp $

BUILDLINK_TREE+=	libmusepack

.if !defined(LIBMUSEPACK_BUILDLINK3_MK)
LIBMUSEPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusepack+=		libmusepack>=1.0.3
BUILDLINK_PKGSRCDIR.libmusepack?=	../../audio/libmusepack
.endif # LIBMUSEPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusepack
