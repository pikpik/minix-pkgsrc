# $NetBSD: Makefile,v 1.2 2008/09/25 12:04:16 taca Exp $

DISTNAME=	rison-1.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rison.rubyforge.org/
COMMENT=	Pure Ruby parser for Rison
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dhaka>=2.2.1:../../devel/ruby-dhaka

pre-configure:
	${CHMOD} 0644 ${WRKSRC}/lib/rison/dump.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
