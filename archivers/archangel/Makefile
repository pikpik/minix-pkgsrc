# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:03 joerg Exp $

DISTNAME=	archangel-20050730
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Compressing archiver which can sign and encrypt entries

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/archangel

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aatar ${PREFIX}/bin/.
	${INSTALL_MAN} ${WRKSRC}/aatar.1 ${PREFIX}/${PKGMANDIR}/man1/.

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
