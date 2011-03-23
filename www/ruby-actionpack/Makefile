# $NetBSD: Makefile,v 1.22 2011/02/09 12:40:51 taca Exp $

DISTNAME=	actionpack-${RUBY_RAILS2_VERSION}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionpack/
COMMENT=	Two-step approach to web response generation
LICENSE=	mit

RUBY_RAILS=	2

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.1.0<1.2.0:../../www/ruby-rack11

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
