# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:24:15 jlam Exp $

DISTNAME=	merb_has_flash-1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/eltiare/merb_has_flash
COMMENT=	Rails-style flash for Merb
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
