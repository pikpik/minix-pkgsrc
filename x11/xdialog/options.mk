# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.xdialog
PKG_SUPPORTED_OPTIONS=		gtk2
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+= --with-gtk2
.include "../../x11/gtk2/buildlink3.mk"
.else
.include "../../x11/gtk/buildlink3.mk"
.endif
