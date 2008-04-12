# $NetBSD: options.mk,v 1.1 2005/10/25 02:06:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gocr
PKG_SUPPORTED_OPTIONS=	tk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		tk

.if !empty(PKG_OPTIONS:Mtk)
DEPENDS+=		tk>=8.4:../../x11/tk
PLIST.tk=		yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gocr.tcl ${PREFIX}/bin
.endif
