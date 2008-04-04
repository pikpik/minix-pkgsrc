# $NetBSD$

DISTNAME=	thoth_flickr-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Flickr plugin for the Thoth blog engine

DEPENDS+=	${RUBY_PKGPREFIX}-net-flickr>=0.0.1:../../www/ruby-net-flickr
DEPENDS+=	thoth>=0.1.0:../../www/thoth

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
