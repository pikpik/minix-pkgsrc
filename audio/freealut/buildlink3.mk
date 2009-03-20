# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/13 14:50:17 drochner Exp $

BUILDLINK_TREE+=	freealut

.if !defined(FREEALUT_BUILDLINK3_MK)
FREEALUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freealut+=	freealut>=1.1.0
BUILDLINK_PKGSRCDIR.freealut?=	../../audio/freealut

.include "../../audio/openal/buildlink3.mk"
.endif # FREEALUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-freealut
