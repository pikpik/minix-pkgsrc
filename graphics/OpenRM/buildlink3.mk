# $NetBSD: buildlink3.mk,v 1.12 2007/02/15 14:58:19 joerg Exp $

BUILDLINK_TREE+=	OpenRM

.if !defined(OPENRM_BUILDLINK3_MK)
OPENRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.OpenRM+=	OpenRM>=1.5.1
BUILDLINK_ABI_DEPENDS.OpenRM?=	OpenRM>=1.5.2nb3
BUILDLINK_PKGSRCDIR.OpenRM?=	../../graphics/OpenRM

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-OpenRM
