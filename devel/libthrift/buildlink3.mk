# $NetBSD: buildlink3.mk,v 1.12 2009/08/26 19:57:07 sno Exp $

BUILDLINK_TREE+=	libthrift

.if !defined(LIBTHRIFT_BUILDLINK3_MK)
LIBTHRIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthrift+=	libthrift>=0.2.0
BUILDLINK_ABI_DEPENDS.libthrift+=	libthrift>=0.2.0
BUILDLINK_PKGSRCDIR.libthrift?=		../../devel/libthrift

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"

.endif # LIBTHRIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthrift
