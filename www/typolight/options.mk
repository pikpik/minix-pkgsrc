# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight
PKG_SUPPORTED_OPTIONS=	typolight-liveupdate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtypolight-liveupdate)
FILES_SUBST+=	TL_UPDATE=YES
.else
FILES_SUBST+=	TL_UPDATE=NO
.endif
