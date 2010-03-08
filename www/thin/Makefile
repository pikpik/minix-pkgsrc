# $NetBSD: Makefile,v 1.4 2008/06/19 15:21:35 taca Exp $

DISTNAME=	thin-1.2.7
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.macournoyer.com/thin/
COMMENT=	Fast and very simple Ruby web server

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.6:../../devel/ruby-eventmachine

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
