# $NetBSD: Makefile,v 1.44 2003/04/22 20:25:10 wiz Exp $

DISTNAME=	tcx-linux
PKGNAME=	tcx-19940124
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ibiblio.unc.edu/pub/Linux/utils/compress/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	transparently compress executables

WRKSRC=		${WRKDIR}/tcx

post-patch:
	cd ${WRKSRC}; ${MV} config.h config.h-pre; ${SED} -e 's|@PREFIX@|"${PREFIX}"|g' < config.h-pre > config.h

.include "../../mk/bsd.pkg.mk"
