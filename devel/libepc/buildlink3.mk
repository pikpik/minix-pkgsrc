# $NetBSD$

BUILDLINK_TREE+=	libepc

.if !defined(LIBEPC_BUILDLINK3_MK)
LIBEPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepc+=	libepc>=0.3.11
BUILDLINK_PKGSRCDIR.libepc?=	../../devel/libepc

.include "../../net/libsoup24/buildlink3.mk"
.endif	# LIBEPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepc
