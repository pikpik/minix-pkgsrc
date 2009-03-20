# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/22 13:06:40 jmcneill Exp $

BUILDLINK_TREE+=	usbids

.if !defined(USBIDS_BUILDLINK3_MK)
USBIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.usbids+=	usbids>=20081118
BUILDLINK_PKGSRCDIR.usbids?=	../../misc/usbids
.endif # USBIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-usbids
