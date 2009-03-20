# $NetBSD: buildlink3.mk,v 1.10 2009/03/05 21:10:27 joerg Exp $

BUILDLINK_TREE+=	openobex

.if !defined(OPENOBEX_BUILDLINK3_MK)
OPENOBEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.3
BUILDLINK_PKGSRCDIR.openobex?=	../../comms/openobex

.include "../../devel/libusb/buildlink3.mk"
.endif # OPENOBEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-openobex
