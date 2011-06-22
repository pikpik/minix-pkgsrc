# $NetBSD: Makefile,v 1.3 2010/10/02 08:58:56 obache Exp $

DISTNAME=	compass-0.11.3
CATEGORIES=	www
#MASTER_SITES=	http://gems.github.com/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/
COMMENT=	Stylesheet authoring framework based on Sass
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.1<4:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-chunky_png>=1.1<2:../../graphics/ruby-chunky_png
DEPENDS+=	${RUBY_PKGPREFIX}-fssm>=0.2.7:../../sysutils/ruby-fssm

CONFLICTS+=	ruby[1-9][0-9]-compass-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
