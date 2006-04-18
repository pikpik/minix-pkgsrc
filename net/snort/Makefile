# $NetBSD: Makefile,v 1.26 2005/01/28 23:02:41 adrianp Exp $
#

.include "Makefile.common"

COMMENT=	The Open Source Network Intrusion Detection System

PKG_OPTIONS_VAR=        PKG_OPTIONS.snort
PKG_SUPPORTED_OPTIONS=  debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.endif

.include "../../mk/bsd.pkg.mk"
