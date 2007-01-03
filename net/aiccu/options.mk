# $NetBSD: options.mk,v 1.1 2006/09/01 06:48:27 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aiccu
PKG_SUPPORTED_OPTIONS=	gnutls
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CFLAGS+=	-D AICCU_GNUTLS
LDFLAGS+=	-lgnutls
.endif
