# $NetBSD: Makefile,v 1.13 2009/06/30 00:07:10 joerg Exp $
#

DISTNAME=	atlc-4.6.0
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atlc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://atlc.sourceforge.net/
COMMENT=	Calculates the impedance of arbitrary cross section transmission lines

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
# note:  the check target builds some of the
# example files which get installed.
BUILD_TARGET=	all check
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

INSTALLATION_DIRS=	share/examples/atlc

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/atlc
	${RM} -f ${DESTDIR}${PREFIX}/share/examples/atlc/Makefile

.include "../../mk/bsd.pkg.mk"
