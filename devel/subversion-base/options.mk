# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.subversion
PKG_SUPPORTED_OPTIONS=	apache22 apr1 serf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapache22) || !empty(PKG_OPTIONS:Mserf)
PKG_OPTIONS+=		apr1
.endif

.if !empty(PKG_OPTIONS:Mapr1) && empty(PKG_OPTIONS:Mapache22)
PKG_OPTIONS+=		apache22
.endif
