# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/12 11:46:21 jmmv Exp $

BUILDLINK_TREE+=	pciids

.if !defined(PCIIDS_BUILDLINK3_MK)
PCIIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pciids+=	pciids>=20061026
BUILDLINK_PKGSRCDIR.pciids?=	../../misc/pciids
.endif # PCIIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pciids
