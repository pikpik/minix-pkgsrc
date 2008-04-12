# $NetBSD: options.mk,v 1.7 2007/04/13 21:25:48 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wine
PKG_SUPPORTED_OPTIONS=	cups opengl sane
PKG_SUGGESTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		opengl

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=		yes
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !empty(PKG_OPTIONS:Msane)
.include "../../graphics/sane-backends/buildlink3.mk"
.endif
