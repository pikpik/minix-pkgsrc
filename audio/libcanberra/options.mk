# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcanberra
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
GCONF_SCHEMAS+=		libcanberra.schemas
PLIST.gtk=		yes
.include "../../x11/gtk2/buildlink3.mk"
.endif
