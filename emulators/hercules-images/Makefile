# $NetBSD: Makefile,v 1.3 2001/02/21 10:18:16 agc Exp $

DISTNAME=		mftr33
PKGNAME=		hercules-images-20010222
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		Images to IPL the Hercules emulator

NO_BUILD=		yes
NO_CONFIGURE=		yes
NO_PATCH=		yes
EXTRACT_ONLY=
WRKSRC=			${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/data/hercules
	cd ${PREFIX}/share/data/hercules;				\
	(${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ; dd if=/dev/zero bs=10k count=2) | ${PAX} -r

.include "../../mk/bsd.pkg.mk"
