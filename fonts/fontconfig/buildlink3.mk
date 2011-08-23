# $NetBSD: buildlink3.mk,v 1.25 2007/10/16 18:12:56 reed Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/fontconfig.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	fontconfig

.if !defined(FONTCONFIG_BUILDLINK3_MK)
FONTCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.4.2
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # FONTCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-fontconfig

.endif
