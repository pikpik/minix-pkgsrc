# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 04:40:37 minskim Exp $

DISTNAME=	feed-normalizer-1.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://feed-normalizer.rubyforge.org/
COMMENT=	Extensible Ruby wrapper for Atom and RSS parsers

DEPENDS+=	hoe>=1.5.0:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-simple-rss>=1.1:../../textproc/ruby-simple-rss
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
