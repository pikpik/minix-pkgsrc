# $NetBSD: Makefile,v 1.2 2000/12/01 01:51:33 jtb Exp $

DISTNAME=		quadpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/quadpack
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quadpack
	for i in doc readme ; do					\
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/quadpack;	\
	done

.include "../../mk/bsd.pkg.mk"
