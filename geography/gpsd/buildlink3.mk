# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:35 joerg Exp $

BUILDLINK_TREE+=	gpsd

.if !defined(GPSD_BUILDLINK3_MK)
GPSD_BUILDLINK3_MK:=

# 2.90 is the beginning of withdrawing of interfaces.  Plus
# it's an ABI.
BUILDLINK_API_DEPENDS.gpsd+=	gpsd>=2.90
BUILDLINK_ABI_DEPENDS.gpsd?=	gpsd>=2.90
BUILDLINK_PKGSRCDIR.gpsd?=	../../geography/gpsd
.endif # GPSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsd
