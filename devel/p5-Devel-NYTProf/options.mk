# $NetBSD: options.mk,v 1.3 2009/06/13 06:46:45 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Devel-NYTProf

PKG_SUPPORTED_OPTIONS=	graphviz
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgraphviz)
DEPENDS+=	graphviz>=2:../../graphics/graphviz
.endif
