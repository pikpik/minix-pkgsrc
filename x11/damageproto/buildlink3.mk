# $NetBSD: buildlink3.mk,v 1.2 2007/01/18 17:30:44 joerg Exp $

BUILDLINK_DEPMETHOD.damageproto?=	build

BUILDLINK_TREE+=	damageproto

.if !defined(DAMAGEPROTO_BUILDLINK3_MK)
DAMAGEPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.damageproto+=	damageproto>=1.1.0
BUILDLINK_PKGSRCDIR.damageproto?=	../../x11/damageproto

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.endif # DAMAGEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-damageproto
