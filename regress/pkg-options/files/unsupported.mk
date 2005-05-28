# $NetBSD: order.mk,v 1.1.1.1 2005/05/16 00:09:03 rillig Exp $
#
# This file test the effect of the PKG_DEFAULT_OPTIONS variable.
#

MAKECONF=		/dev/null

PKG_SUPPORTED_OPTIONS=	a
PKG_SUGGESTED_OPTIONS=	
PKG_OPTIONS_VAR=	PKG_OPTIONS.foo
PKG_DEFAULT_OPTIONS=	
PKG_OPTIONS.foo=	b

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:Q}
