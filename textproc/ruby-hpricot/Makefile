# $NetBSD: Makefile,v 1.5 2009/11/23 14:40:02 fhajny Exp $

DISTNAME=	hpricot-0.8.2
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://wiki.github.com/hpricot/hpricot
COMMENT=	Fast, enjoyable HTML parser for Ruby
LICENSE=	mit

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
