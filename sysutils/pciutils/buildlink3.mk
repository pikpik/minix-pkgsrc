# $NetBSD: buildlink3.mk,v 1.7 2008/11/03 22:01:29 bjs Exp $

BUILDLINK_TREE+=	pciutils

.if !defined(PCIUTILS_BUILDLINK3_MK)
PCIUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pciutils+=	pciutils>=3.0.2
BUILDLINK_PKGSRCDIR.pciutils?=	../../sysutils/pciutils
BUILDLINK_DEPMETHOD.pciutils?=	build
.endif # PCIUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pciutils
