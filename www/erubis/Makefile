# $NetBSD: Makefile,v 1.2 2008/04/04 15:22:47 jlam Exp $

DISTNAME=	erubis-2.6.6
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast, secure, and extensible implementation of eRuby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-abstract>=1.0.0:../../devel/ruby-abstract

CONFLICTS+=	ruby[1-9][0-9]-erubis-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
