# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:09 jlam Exp $

BUILDLINK_TREE+=	libol

.if !defined(LIBOL_BUILDLINK3_MK)
LIBOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libol+=	libol>=0.3.17
BUILDLINK_PKGSRCDIR.libol?=	../../sysutils/libol
.endif # LIBOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libol
