# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:26:29 jlam Exp $

DISTNAME=	net-flickr-0.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://wonko.com/software/net-flickr/
HOMEPAGE=	http://code.google.com/p/net-flickr/
COMMENT=	Flickr REST client
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.5:../../textproc/ruby-hpricot

GEM_CLEANBUILD=	ext/patron/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
