# $NetBSD: Makefile,v 1.7 2010/03/09 12:44:29 fhajny Exp $

DISTNAME=	hoe-2.6.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-hoe-* hoe-*

DEPENDS+=	${RUBY_PKGPREFIX}-rubyforge>=2.0.4:../../devel/rubyforge

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
