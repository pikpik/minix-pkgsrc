# $NetBSD: Makefile,v 1.4 2009/11/23 14:21:43 fhajny Exp $

DISTNAME=	heckle-1.4.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/heckle/
COMMENT=	Code mutation tester for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=2.0.0:../../devel/ruby-parsetree
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.6:../../devel/ruby2ruby
DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=3.5.2:../../devel/ZenTest

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
