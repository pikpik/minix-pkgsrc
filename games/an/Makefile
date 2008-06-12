# $NetBSD: Makefile,v 1.5 2006/07/02 14:49:50 joerg Exp $
#

DISTNAME=	an-0.93
CATEGORIES=	games
MASTER_SITES=	ftp://suburbia.net/pub/rmj/

MAINTAINER=	jonb@NetBSD.org
COMMENT=	Very fast anagram generator

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS=	INSTALLDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

WRKSRC=		${WRKDIR}/an-0.93

.include "../../mk/bsd.pkg.mk"
