# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:13 jlam Exp $

DISTNAME=	merb_test_unit-0.9.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides support for Test::Unit
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.9:../../www/merb-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
