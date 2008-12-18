# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.libunique

PKG_SUPPORTED_OPTIONS=		dbus
PKG_SUGGESTED_OPTIONS=		dbus

.include "../../mk/bsd.options.mk"

#
# D-BUS support
#
.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif
