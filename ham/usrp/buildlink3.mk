# $NetBSD: buildlink3.mk,v 1.11 2007/08/08 03:24:47 wulf Exp $

BUILDLINK_TREE+=	usrp

.if !defined(USRP_BUILDLINK3_MK)
USRP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.usrp+=	usrp>=3.0.4
BUILDLINK_PKGSRCDIR.usrp?=	../../ham/usrp

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.endif # USRP_BUILDLINK3_MK

BUILDLINK_TREE+=	-usrp
