# $NetBSD: buildlink3.mk,v 1.2 2008/03/04 15:52:15 shannonjr Exp $

BUILDLINK_TREE+=	pcsc-lite

.if !defined(PCSC_LITE_BUILDLINK3_MK)
PCSC_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcsc-lite+=	pcsc-lite>=1.4.99
BUILDLINK_PKGSRCDIR.pcsc-lite?=	../../security/pcsc-lite

.include "../../devel/libusb/buildlink3.mk"
.endif # PCSC_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcsc-lite
