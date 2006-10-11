# $NetBSD: options.mk,v 1.1 2006/06/17 13:46:34 rillig Exp $
#

# XXX This usage of bsd.options.mk is incorrect.  The package should
# to be split into three packages
#   pinentry-curses
#   pinentry-gtk
#   pinentry-qt

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=	gtk qt
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-pinentry-gtk
PLIST_SUBST+=		USE_GTK=
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-gtk
PLIST_SUBST+=		USE_GTK='@comment '
.endif

.if !empty(PKG_OPTIONS:Mqt)
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--enable-pinentry-qt
PLIST_SUBST+=		USE_QT=
.  include "../../x11/qt3-libs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-qt
PLIST_SUBST+=		USE_QT='@comment '
.endif
