# $NetBSD: unsupported.mk,v 1.1 2005/05/28 12:16:43 dillo Exp $
#
# This file tests that selecting no option from a requried group
# causes the package build to fail.
#

MAKECONF=		/dev/null

PKG_OPTIONS_VAR=	PKG_OPTIONS.unused
PKG_SUPPORTED_OPTIONS=	single
PKG_OPTIONS_REQUIRED_GROUPS=	req
PKG_OPTIONS_GROUP.req=	a b

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:Q}
