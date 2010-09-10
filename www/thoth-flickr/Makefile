# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:27:05 jlam Exp $

DISTNAME=	thoth_flickr-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thothblog.org/
COMMENT=	Flickr plugin for the Thoth blog engine
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-net-flickr>=0.0.1:../../www/ruby-net-flickr
DEPENDS+=	${RUBY_PKGPREFIX}-thoth>=0.1.0:../../www/thoth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
