# $NetBSD: Makefile,v 1.12 2012/12/16 16:47:12 taca Exp $

DISTNAME=	rspec-2.13.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2.13.0<2.14:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=2.13.0<2.14:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=2.13.0<2.14:../../devel/ruby-rspec-mocks

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
