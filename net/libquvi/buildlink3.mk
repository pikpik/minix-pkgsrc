# $NetBSD$

BUILDLINK_TREE+=	libquvi

.if !defined(LIBQUVI_BUILDLINK3_MK)
LIBQUVI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libquvi+=	libquvi>=0.4.0
BUILDLINK_PKGSRCDIR.libquvi?=	../../net/libquvi

.include "../../net/libquvi-scripts/buildlink3.mk"
.endif	# LIBQUVI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libquvi
