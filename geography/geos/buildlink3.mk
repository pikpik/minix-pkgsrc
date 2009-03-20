# $NetBSD: buildlink3.mk,v 1.7 2008/02/16 01:29:00 gdt Exp $

BUILDLINK_TREE+=	geos

.if !defined(GEOS_BUILDLINK3_MK)
GEOS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.geos+=	geos>=2.2.3
BUILDLINK_ABI_DEPENDS.geos?=	geos>=3.0.0
BUILDLINK_PKGSRCDIR.geos?=	../../geography/geos
.endif # GEOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-geos
