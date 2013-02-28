# $NetBSD$

BUILDLINK_TREE+=	libsodium

.if !defined(LIBSODIUM_BUILDLINK3_MK)
LIBSODIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsodium+=	libsodium>=0.3
BUILDLINK_PKGSRCDIR.libsodium?=	../../security/libsodium
.endif	# LIBSODIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsodium
