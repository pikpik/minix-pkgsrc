# $NetBSD: Makefile,v 1.6 2003/09/07 09:32:48 wiz Exp $
#

DISTNAME=	lq-sp-1.3.4.10
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	Modified SP package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++

# doesn't build (LP64 bugs)
NOT_FOR_PLATFORM=	*-*-alpha

INSTALLATION_DIRS+=	bin

do-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.netbsd
	${SED} -e 's:@PREFIX@:${PREFIX}:'	\
	    < ${WRKSRC}/Makefile.netbsd		\
	    > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgmls/lq-nsgmls ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
