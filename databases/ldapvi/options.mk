# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.ldapvi
PKG_SUPPORTED_OPTIONS=		sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
