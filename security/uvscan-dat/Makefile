# $NetBSD$
#

DISTNAME=	dat-4080
PKGNAME=	uvscan-${DISTNAME}
NO_WRKSUBDIR=	yes
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/datfiles/4.x/nai/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nai.com/asp_set/download/dats/mcafee_4x.asp

NO_CONFIGURE=	YES
NO_BUILD=	YES

MIRROR_DISTFILE=no
RESTRICTED=	"restricted to the license terms set for VirusScan"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/uvscan
.for file in clean.dat internet.dat names.dat scan.dat
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/libexec/uvscan
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uvscan
.for file in reseller.txt readme.txt packing.lst
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/uvscan
.endfor

.include "../../mk/bsd.pkg.mk"
