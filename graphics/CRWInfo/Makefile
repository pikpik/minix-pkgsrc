# $NetBSD$
#

DISTNAME=	CRWInfo-0.2
CATEGORIES=	graphics
MASTER_SITES=	http://neuemuenze.heim1.tu-clausthal.de/~sven/crwinfo/

MAINTAINER=	kirtai@users.sourceforge.net
HOMEPAGE=	http://neuemuenze.heim1.tu-clausthal.de/~sven/crwinfo/
COMMENT=	Extracts exposure information and thumbnails from Canon RAW files

NO_CONFIGURE=		yes
USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crwinfo ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/crwinfo/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/crwinfo/

.include "../../mk/bsd.pkg.mk"
