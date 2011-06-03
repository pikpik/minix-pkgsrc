# $NetBSD: Makefile,v 1.3 2011/02/09 13:00:50 taca Exp $

DISTNAME=	activeresource-${RUBY_RAILS3_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	REST modeling framework (part of Rails)
LICENSE=	mit

RUBY_RAILS=	3

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
