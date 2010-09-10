# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:31 jlam Exp $

DISTNAME=	mongrel_cluster-1.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Mongrel plugin to manage a mongrel cluster
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin
DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
