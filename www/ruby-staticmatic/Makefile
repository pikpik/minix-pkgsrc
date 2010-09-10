# $NetBSD: Makefile,v 1.1.1.1 2009/11/01 03:16:58 seb Exp $

DISTNAME=	staticmatic-0.10.8
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staticmatic.net
COMMENT=	Lightweight static site framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.0:../../textproc/ruby-haml
DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.1.5:../../www/mongrel

CONFLICTS+=	ruby[1-9][0-9]-staticmatic-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
