# $NetBSD$

BUILDLINK_TREE+=	libftdi

.if !defined(LIBFTDI_BUILDLINK3_MK)
LIBFTDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi+=	libftdi>=0.18
BUILDLINK_PKGSRCDIR.libftdi?=	../../devel/libftdi

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBFTDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi
