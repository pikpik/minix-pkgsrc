# $NetBSD: options.mk,v 1.3 2005/06/10 18:21:45 wiz Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.imlib2
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif
