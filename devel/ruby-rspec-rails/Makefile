# $NetBSD$

DISTNAME=	rspec-rails-2.6.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	A test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=2.6.0<2.7:../../devel/ruby-rspec

RUBY_RAILS=	3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
