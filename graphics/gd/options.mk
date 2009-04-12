# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gd
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ENV+= 	X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}
CONFIGURE_ARGS+=        --with-xpm
.else
CONFIGURE_ARGS+=        --without-xpm
.endif
