# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gocr
PKG_SUPPORTED_OPTIONS=	tk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtk)
DEPENDS+=		tk>=8.4:../../x11/tk
PLIST_SUBST+=		TK=""

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gocr.tcl ${PREFIX}/bin
.else
PLIST_SUBST+=		TK="@comment "
.endif
