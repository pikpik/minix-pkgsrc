# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 04:55:33 minskim Exp $

DISTNAME=	erubis-2.5.0
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast, secure, and extensible implementation of eRuby

DEPENDS+=	${RUBY_PKGPREFIX}-abstract>=1.0.0:../../devel/ruby-abstract

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
