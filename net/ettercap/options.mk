# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ettercap
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif
