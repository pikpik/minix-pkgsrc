# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm
PKG_SUGGESTED_OPTIONS=		softhsm

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm)
.include "../../security/softhsm/buildlink3.mk"
.endif
