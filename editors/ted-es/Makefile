# $NetBSD: Makefile,v 1.2 2001/05/19 17:18:43 wiz Exp $

DISTNAME=	Ted_es_ES
PKGNAME=	ted-es-2.11
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Spanish spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.11
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Spanish.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
