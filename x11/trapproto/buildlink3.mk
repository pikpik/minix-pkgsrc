# $NetBSD: buildlink3.mk,v 1.2 2006/12/17 22:38:14 joerg Exp $

BUILDLINK_DEPMETHOD.trapproto?=	build

BUILDLINK_TREE+=	trapproto

.if !defined(TRAPPROTO_BUILDLINK3_MK)
TRAPPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trapproto+=	trapproto>=3.4.3
BUILDLINK_PKGSRCDIR.trapproto?=	../../x11/trapproto

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # TRAPPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-trapproto
