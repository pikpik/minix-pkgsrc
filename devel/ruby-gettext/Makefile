# $NetBSD: Makefile,v 1.10 2010/02/02 02:18:38 taca Exp $

DISTNAME=	gettext-2.1.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-gettext.html
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

pre-configure:
	cd ${WRKSRC}; ${FIND} . -type f -print | ${XARGS} ${CHMOD} g-w
	${CHMOD} -x ${WRKSRC}/samples/makemo.rb
	${RM} -f ${WRKSRC}/samples/cgi/po/bg/#main.po#

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
