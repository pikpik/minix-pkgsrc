# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs-w3m
PKG_SUPPORTED_OPTIONS=	emacs-w3m-mew

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Memacs-w3m-mew)
.include "../../mail/mew/buildlink3.mk"
PLIST_SUBST+=	FOR_mew=
.else
PLIST_SUBST+=	FOR_mew="@comment "
.endif
