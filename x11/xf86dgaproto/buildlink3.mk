# $NetBSD: buildlink3.mk,v 1.2 2008/01/15 23:27:32 wiz Exp $

BUILDLINK_DEPMETHOD.xf86dgaproto?=	build

BUILDLINK_TREE+=	xf86dgaproto

.if !defined(XF86DGAPROTO_BUILDLINK3_MK)
XF86DGAPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xf86dgaproto+=	xf86dgaproto>=2.0.3
BUILDLINK_PKGSRCDIR.xf86dgaproto?=	../../x11/xf86dgaproto

.include "../../x11/xproto/buildlink3.mk"
.endif # XF86DGAPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86dgaproto
