# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdepim
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
PLIST_SUBST+=	HAVE_SASL=""
.else
PLIST_SUBST+=	HAVE_SASL="@comment "
.endif
