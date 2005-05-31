# $NetBSD: simple.mk,v 1.1.1.1 2005/05/16 00:09:03 rillig Exp $
#
# This file test a very simple options configuration.
#

MAKECONF=			/dev/null

PKG_OPTIONS_VAR=		PKG_OPTIONS.foo
PKG_SUPPORTED_OPTIONS=		new
PKG_OPTIONS_LEGACY_OPTS+=	old:new
PKG_OPTIONS.foo=		old

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_OPTIONS:M*:Q}
