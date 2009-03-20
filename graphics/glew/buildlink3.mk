# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/08/15 15:21:27 abs Exp $

BUILDLINK_TREE+=	glew

.if !defined(GLEW_BUILDLINK3_MK)
GLEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glew+=	glew>=1.3.4
BUILDLINK_ABI_DEPENDS.glew+=	glew>=1.3.4
BUILDLINK_PKGSRCDIR.glew?=	../../graphics/glew

.include "../../graphics/MesaLib/buildlink3.mk"
.endif # GLEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glew
