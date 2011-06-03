# $NetBSD: options.mk,v 1.1.1.1 2010/05/06 12:50:17 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm
PKG_SUGGESTED_OPTIONS=		softhsm

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm)
DEPENDS+=	softhsm-[0-9]*:../../security/softhsm
.include "../../security/softhsm/buildlink3.mk"
.endif
