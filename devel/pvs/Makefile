# $NetBSD: Makefile,v 1.45 2012/10/31 11:19:27 asau Exp $
#

DISTNAME=		pvs-${VERSION}
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel lang
MASTER_SITES=		ftp://ftp.csl.sri.com/pub/pvs/pvs${VERSION}/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}-${MAINFILEEXT}${EXTRACT_SUFX} \
			pvs-${VERSION}-system${EXTRACT_SUFX} \
			pvs-${VERSION}-libraries${EXTRACT_SUFX}
LICENSE=		pvs-license

# not quite sure about this, but to be on the safe side:
RESTRICTED=		Redistribution not permitted - see ${HOMEPAGE}license.html
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pvs.csl.sri.com/
COMMENT=		The PVS Specification and Verification System

DEPENDS+=		tex-amsmath>=2.13nb2:../../print/tex-amsmath
DEPENDS+=		tk>=8.0:../../x11/tk

USE_TOOLS+=	pax

EMUL_PLATFORMS+=	linux-i386 solaris-sparc

WRKSRC=			${WRKDIR}
VERSION=		3.2
INFO_FILES=		yes

MESSAGE_SRC=		${PKGDIR}/MESSAGE.${EMUL_PLATFORM}
MAINFILEEXT=		${EMUL_OPSYS}

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|" ${WRKSRC}/pvs > ${WRKSRC}/pvs.tmp
	${MV} -f ${WRKSRC}/pvs.tmp ${WRKSRC}/pvs
	${RM} -f ${WRKSRC}/pvs.orig
	${RM} -f ${WRKSRC}/doc/release-notes/pvs-release-notes.info.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pvs ${DESTDIR}${PREFIX}/bin/pvs
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/pvs
	cd ${WRKSRC} && pax -s ,^./[.].*,, -rw . ${DESTDIR}${PREFIX}/pvs
	${CHMOD} 755 ${DESTDIR}${PREFIX}/pvs/pvs

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
