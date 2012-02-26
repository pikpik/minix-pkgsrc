# $NetBSD$

BUILDLINK_TREE+=	opencsg

.if !defined(OPENCSG_BUILDLINK3_MK)
OPENCSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencsg+=	opencsg>=1.3.2
BUILDLINK_PKGSRCDIR.opencsg?=	../../graphics/opencsg

.include "../../graphics/glew/buildlink3.mk"
.endif	# OPENCSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencsg
