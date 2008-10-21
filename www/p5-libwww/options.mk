# $NetBSD: options.mk,v 1.1 2007/11/24 16:18:16 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-libwww

PKG_SUPPORTED_OPTIONS=	libwww-aliases

.include "../../mk/bsd.options.mk"

###
### Do we install aliases ?
###
.if !empty(PKG_OPTIONS:Mlibwww-aliases)
MAKE_PARAMS+=		--aliases
.endif
