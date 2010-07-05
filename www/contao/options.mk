# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.contao${CT_VER}
PKG_SUPPORTED_OPTIONS=	contao-liveupdate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcontao-liveupdate)
FILES_SUBST+=	CT_UPDATE=YES
.else
FILES_SUBST+=	CT_UPDATE=NO
.endif
