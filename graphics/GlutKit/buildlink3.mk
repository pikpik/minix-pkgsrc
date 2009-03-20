# $NetBSD: buildlink3.mk,v 1.10 2008/01/18 05:06:38 tnn Exp $

BUILDLINK_TREE+=	GlutKit

.if !defined(GLUTKIT_BUILDLINK3_MK)
GLUTKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GlutKit+=	GlutKit>=0.3.1r2nb4
BUILDLINK_ABI_DEPENDS.GlutKit?=	GlutKit>=0.3.1r2nb14
BUILDLINK_PKGSRCDIR.GlutKit?=	../../graphics/GlutKit

.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif # GLUTKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-GlutKit
