# $NetBSD: Makefile,v 1.9 2008/10/07 05:28:33 minskim Exp $

DISTNAME=	mongrel-1.1.5
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Fast HTTP library and server for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.3:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin

RUBY_REQD=	1.8.6.110

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
