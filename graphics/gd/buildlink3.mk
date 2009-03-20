# $NetBSD: buildlink3.mk,v 1.16 2008/11/20 17:25:01 wiz Exp $

BUILDLINK_TREE+=	gd

.if !defined(GD_BUILDLINK3_MK)
GD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gd+=		gd>=2.0.15nb1
BUILDLINK_ABI_DEPENDS.gd+=	gd>=2.0.33nb3
BUILDLINK_PKGSRCDIR.gd?=	../../graphics/gd

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.endif # GD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gd
