# $NetBSD: buildlink3.mk,v 1.1 2007/03/18 18:56:30 wiz Exp $

BUILDLINK_TREE+=	enca

.if !defined(ENCA_BUILDLINK3_MK)
ENCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enca+=	enca>=1.9
BUILDLINK_PKGSRCDIR.enca?=	../../textproc/enca
.endif # ENCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-enca
