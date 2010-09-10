# $NetBSD: Makefile,v 1.2 2008/04/04 15:21:25 jlam Exp $

DISTNAME=	feed-normalizer-1.5.2
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/aasmith/feed-normalizer
COMMENT=	Extensible Ruby wrapper for Atom and RSS parsers
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=1.5.0:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-simple-rss>=1.1:../../textproc/ruby-simple-rss
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
