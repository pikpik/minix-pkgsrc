# $NetBSD: options.mk,v 1.4 2010/01/17 17:38:17 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xskat

PKG_SUPPORTED_OPTIONS=	altenburger_cards
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maltenburger_cards)
WITH_ALTENBURGER_CARDS=1
.endif
