# $NetBSD: Makefile,v 1.6 2010/09/10 05:07:22 taca Exp $

DISTNAME=	rubigen-1.5.5
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drnic.github.com/rubigen
COMMENT=	Ruby stub generator
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.5:../../devel/ruby-activesupport

CONFLICTS+=	ruby[1-9][0-9]-rubigen-* rubigen-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
