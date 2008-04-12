# $NetBSD: options.mk,v 1.2 2005/11/04 17:22:08 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.smpeg
PKG_SUPPORTED_OPTIONS=	gtk-player opengl-player

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk opengl

.if !empty(PKG_OPTIONS:Mgtk-player)
PLIST.gtk=		yes
CONFIGURE_ARGS+=	--enable-gtk-player
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk-player --disable-gtk-test
.endif

.if !empty(PKG_OPTIONS:Mopengl-player)
PLIST.opengl=		yes
CONFIGURE_ARGS+=	--enable-opengl-player
.  include "../../graphics/glu/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl-player
.endif
