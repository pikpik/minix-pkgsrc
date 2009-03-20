# $NetBSD: buildlink3.mk,v 1.3 2008/07/30 09:56:48 wiz Exp $

BUILDLINK_TREE+=	inputproto

.if !defined(INPUTPROTO_BUILDLINK3_MK)
INPUTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.4
BUILDLINK_PKGSRCDIR.inputproto?=	../../x11/inputproto
BUILDLINK_DEPMETHOD.inputproto?=	build
.endif # INPUTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-inputproto
