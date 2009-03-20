# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/05 20:28:24 hasso Exp $

BUILDLINK_TREE+=	libp11

.if !defined(LIBP11_BUILDLINK3_MK)
LIBP11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libp11+=	libp11>=0.2.4
BUILDLINK_PKGSRCDIR.libp11?=	../../security/libp11

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBP11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libp11
