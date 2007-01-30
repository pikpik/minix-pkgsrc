# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.daapd
PKG_SUPPORTED_OPTIONS=	mpeg4ip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.include "../../multimedia/mpeg4ip/buildlink3.mk"
MAKE_ENV+= WITH_FAAD=1
.else
MAKE_ENV+= WITH_FAAD=0
.endif
