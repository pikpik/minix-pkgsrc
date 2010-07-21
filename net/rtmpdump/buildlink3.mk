# $NetBSD$

BUILDLINK_TREE+=	rtmpdump

.if !defined(RTMPDUMP_BUILDLINK3_MK)
RTMPDUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtmpdump+=	rtmpdump>=2.3
BUILDLINK_PKGSRCDIR.rtmpdump?=	../../net/rtmpdump

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# RTMPDUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtmpdump
