# $NetBSD: buildlink3.mk,v 1.12 2008/01/18 05:06:38 tnn Exp $

BUILDLINK_TREE+=	SDLKit

.if !defined(SDLKIT_BUILDLINK3_MK)
SDLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDLKit+=	SDLKit>=0.3.1r2nb5
BUILDLINK_ABI_DEPENDS.SDLKit?=	SDLKit>=0.3.1r2nb17
BUILDLINK_PKGSRCDIR.SDLKit?=	../../graphics/SDLKit

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/RenderKit/buildlink3.mk"
.endif # SDLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDLKit
