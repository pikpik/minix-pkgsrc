# $NetBSD: Makefile,v 1.7 2008/01/18 05:06:25 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.conserver8
PKG_SUPPORTED_OPTIONS=	pam ssl uds
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

.if !empty(PKG_OPTIONS:Muds)
CONFIGURE_ARGS+=	--with-uds
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
. include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
