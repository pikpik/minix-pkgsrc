# $NetBSD: buildlink3.mk,v 1.1 2009/03/17 23:40:37 jmcneill Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=2.26.0
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero
.endif # BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
