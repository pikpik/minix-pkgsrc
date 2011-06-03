# $NetBSD: options.mk,v 1.1 2011/03/23 21:44:24 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.podofo
PKG_SUPPORTED_OPTIONS=		lua

.include "../../mk/bsd.options.mk"

###
### Lua support
###
.if !empty(PKG_OPTIONS:Mlua)
.  include "../../lang/lua/buildlink3.mk"
CMAKE_ARGS+=	-DLUA_ENABLED:LUA_ENABLED=true
.endif
