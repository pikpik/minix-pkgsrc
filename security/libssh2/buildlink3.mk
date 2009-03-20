# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/03/02 14:11:54 bjs Exp $

BUILDLINK_TREE+=	libssh2

.if !defined(LIBSSH2_BUILDLINK3_MK)
LIBSSH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh2+=	libssh2>=0.18
BUILDLINK_PKGSRCDIR.libssh2?=	../../security/libssh2

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBSSH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh2
