# $NetBSD: buildlink3.mk,v 1.3 2007/12/17 14:24:06 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/sm.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libSM

.if !defined(LIBSM_BUILDLINK3_MK)
LIBSM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libSM+=	libSM>=0.99.2
BUILDLINK_PKGSRCDIR.libSM?=	../../x11/libSM

.include "../../x11/libICE/buildlink3.mk"
.endif # LIBSM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libSM

.endif
