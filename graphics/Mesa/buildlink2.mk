# $NetBSD: buildlink2.mk,v 1.4 2003/07/15 23:31:22 jschauma Exp $

.if !defined(MESA_BUILDLINK2_MK)
MESA_BUILDLINK2_MK=	# defined

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.endif	# MESA_BUILDLINK2_MK
