# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:10:49 jlam Exp $

BUILDLINK_TREE+=	pico

.if !defined(PICO_BUILDLINK3_MK)
PICO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pico+=	pico>=4.10
BUILDLINK_PKGSRCDIR.pico?=	../../editors/pico
.endif # PICO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pico
