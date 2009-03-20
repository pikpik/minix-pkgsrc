# $NetBSD: buildlink3.mk,v 1.4 2007/12/17 13:27:28 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/ice.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libICE

.if !defined(LIBICE_BUILDLINK3_MK)
LIBICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libICE+=	libICE>=0.99.1
BUILDLINK_PKGSRCDIR.libICE?=	../../x11/libICE
.endif # LIBICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libICE

.endif
