# $NetBSD: Makefile,v 1.1.1.1 2004/02/20 13:43:28 drochner Exp $
#

DISTNAME=		dcraw
PKGNAME=		dcraw-1.175
CATEGORIES=		graphics
# distfile changes frequently, use copy on ftp.NetBSD.org
#MASTER_SITES=		http://www.cybercom.net/~dcoffin/dcraw/
MASTER_SITES=		${MASTER_SITE_BACKUP:=${PKGNAME}/}
DISTFILES=		dcraw.c dcraw.1
DIST_SUBDIR=		${PKGNAME}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=		Raw digital camera decoder

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=		yes

do-extract:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC})

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} dcraw.c -o dcraw ${LDFLAGS} -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dcraw.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
