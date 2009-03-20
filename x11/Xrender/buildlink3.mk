# $NetBSD: buildlink3.mk,v 1.44 2006/12/12 21:52:37 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	Xrender

.if !defined(XRENDER_BUILDLINK3_MK)
XRENDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.2
BUILDLINK_ABI_DEPENDS.Xrender+=	Xrender>=0.9.0nb1
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.endif # XRENDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xrender
