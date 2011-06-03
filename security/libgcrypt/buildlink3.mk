# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:25:18 joerg Exp $

BUILDLINK_TREE+=	libgcrypt

.if !defined(LIBGCRYPT_BUILDLINK3_MK)
LIBGCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.0
BUILDLINK_ABI_DEPENDS.libgcrypt+=	libgcrypt>=1.4.6nb2
BUILDLINK_PKGSRCDIR.libgcrypt?=	../../security/libgcrypt

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBGCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcrypt
