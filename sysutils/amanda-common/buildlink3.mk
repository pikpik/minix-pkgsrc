# $NetBSD: buildlink3.mk,v 1.11 2008/02/15 16:23:09 gdt Exp $

BUILDLINK_TREE+=	amanda-common

.if !defined(AMANDA_COMMON_BUILDLINK3_MK)
AMANDA_COMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.amanda-common+=	amanda-common>=2.5.2p1
BUILDLINK_ABI_DEPENDS.amanda-common+=	amanda-common>=2.5.2p1
BUILDLINK_PKGSRCDIR.amanda-common?=	../../sysutils/amanda-common
.endif # AMANDA_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-amanda-common
