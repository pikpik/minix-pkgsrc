# $NetBSD: Makefile,v 1.1 2002/05/08 15:42:00 jschauma Exp $
#

DISTNAME=	joos-0.1
CATEGORIES=     lang
MASTER_SITES=	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

USE_JAVA=	run
PKG_JVM=	sun-jdk

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/joos
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/joos

.include "../../mk/bsd.pkg.mk"
