# $NetBSD: buildlink3.mk,v 1.1 2009/03/10 23:12:29 gdt Exp $

BUILDLINK_TREE+=	gpsd

.if !defined(GPSD_BUILDLINK3_MK)
GPSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpsd+=	gpsd>=2.37nb1
BUILDLINK_PKGSRCDIR.gpsd?=	../../geography/gpsd
.endif # GPSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsd
