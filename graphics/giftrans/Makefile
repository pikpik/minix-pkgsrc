# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:47 jlam Exp $
#

DISTNAME=	sgif1122
PKGNAME=	giftrans-1.12.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.rz.uni-karlsruhe.de/pub/net/www/tools/giftrans/
COMMENT=	Manipulate GIF89a images' transparency, comment and other data

WRKSRC=		${WRKDIR}/usr/src/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
