# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.yelp

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mseamonkey)
BROKEN=		seamonkey backend is currently not supported
.endif
