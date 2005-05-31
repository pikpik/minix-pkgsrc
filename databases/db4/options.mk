# $NetBSD: options.mk,v 1.1 2004/12/27 04:27:49 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4
PKG_SUPPORTED_OPTIONS=	java
PKG_OPTIONS_LEGACY_VARS+=	WITH_JAVA:java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--disable-java
.endif
