# $NetBSD$

BUILDLINK_TREE+=	glpng

.if !defined(GLPNG_BUILDLINK3_MK)
GLPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpng+=	glpng>=1.45.20081203
BUILDLINK_PKGSRCDIR.glpng?=	../../graphics/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GLPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpng
