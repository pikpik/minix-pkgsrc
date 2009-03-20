# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:51 jlam Exp $

BUILDLINK_TREE+=	Hermes

.if !defined(HERMES_BUILDLINK3_MK)
HERMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Hermes+=	Hermes>=1.3.2
BUILDLINK_ABI_DEPENDS.Hermes+=	Hermes>=1.3.3nb2
BUILDLINK_PKGSRCDIR.Hermes?=	../../graphics/hermes
.endif # HERMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-Hermes
