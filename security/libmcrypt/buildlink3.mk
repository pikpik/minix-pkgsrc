# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:07 jlam Exp $

BUILDLINK_TREE+=	libmcrypt

.if !defined(LIBMCRYPT_BUILDLINK3_MK)
LIBMCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmcrypt+=	libmcrypt>=2.5.6
BUILDLINK_ABI_DEPENDS.libmcrypt+=	libmcrypt>=2.5.7nb1
BUILDLINK_PKGSRCDIR.libmcrypt?=	../../security/libmcrypt
.endif # LIBMCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmcrypt
