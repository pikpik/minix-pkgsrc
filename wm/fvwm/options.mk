# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.fvwm
PKG_SUPPORTED_OPTIONS=		gtk rplay
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_GTK:gtk
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_RPLAY:rplay

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gtk-prefix
.endif

.if !empty(PKG_OPTIONS:Mrplay)
.  include "../../audio/rplay/buildlink3.mk"
.endif
