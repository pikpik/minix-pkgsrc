# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:03 jlam Exp $

DISTNAME=		dfftpack-20001209
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Double precision version of FFTPACK

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/dfftpack

INSTALLATION_DIRS=	lib share/doc/dfftpack share/examples/dfftpack

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@for f in README doc doc.double ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/dfftpack ; done
	${INSTALL_DATA} ${WRKSRC}/test.f ${PREFIX}/share/examples/dfftpack

.include "../../mk/bsd.pkg.mk"
