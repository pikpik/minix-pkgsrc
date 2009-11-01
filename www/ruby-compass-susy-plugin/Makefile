# $NetBSD$

DISTNAME=	compass-susy-plugin-0.6.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://gemcutter.org/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oddbird.net/susy/
COMMENT=	Compass plugin grid system

GEM_BUILD=	gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-compass-[0-9]*:../../www/ruby-compass

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
