# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 20:11:57 joerg Exp $

BUILDLINK_DEPMETHOD.scrnsaverproto?=	build

BUILDLINK_TREE+=	scrnsaverproto

.if !defined(SCRNSAVERPROTO_BUILDLINK3_MK)
SCRNSAVERPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scrnsaverproto+=	scrnsaverproto>=1.1.0
BUILDLINK_PKGSRCDIR.scrnsaverproto?=	../../x11/scrnsaverproto

.include "../../x11/xproto/buildlink3.mk"
.endif # SCRNSAVERPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-scrnsaverproto
