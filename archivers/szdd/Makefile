# $NetBSD$
#

DISTNAME=		xfd_SZDD
PKGNAME=		szdd-1.3
CATEGORIES=		archivers
MASTER_SITES=		http://www.kyz.uklinux.net/downloads/
EXTRACT_SUFX=		.lha

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.kyz.uklinux.net/packers.php3#SZDD
COMMENT=		extracts Microsoft SZDD files

NO_WRKSUBDIR=		yes

pre-build:
	cd ${WRKSRC} && make clean

do-install:
	${CP} ${WRKSRC}/szddexpand ${WRKSRC}/szddinfo ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
