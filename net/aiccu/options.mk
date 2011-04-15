# $NetBSD: options.mk,v 1.2 2007/01/03 15:25:12 tv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aiccu
PKG_SUPPORTED_OPTIONS=	gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CFLAGS+=	-D AICCU_GNUTLS
LDFLAGS+=	-lgnutls
.endif
