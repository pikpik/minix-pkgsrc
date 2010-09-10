# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:38 jlam Exp $

DISTNAME=	mongrel_config-0.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Mongrel web-based configuration tool
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin
DEPENDS+=	${RUBY_PKGPREFIX}-camping>=1.5:../../www/camping

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
