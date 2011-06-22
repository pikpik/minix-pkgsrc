# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 04:05:22 taca Exp $

DISTNAME=	rack-mount-0.6.14
CATEGORIES=	www

# Note: www/ruby-actionpack3 needs ruby-rack-mount<0.7.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/josh/rack-mount
COMMENT=	Stackable dynamic tree based Rack router
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
