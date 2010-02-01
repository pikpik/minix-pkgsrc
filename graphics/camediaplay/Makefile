# $NetBSD: Makefile,v 1.14 2007/12/02 00:04:48 wiz Exp $

DISTNAME=	camediaplay-20010211
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.itojun.org/pub/digi-cam/C-400L/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Digital camera downloading tool for Epson/Sanyo/Olympus/Agfa camera

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/camediaplay/build
GNU_CONFIGURE=	yes

DOC=	README.english README.japanese PROTOCOL

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/camediaplay

SPECIAL_PERMS+=	bin/camediaplay uucp bin 04555

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/camediaplay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../src/camediaplay.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/camediaplay.1
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i \
			${DESTDIR}${PREFIX}/share/doc/camediaplay; \
	done

.include "../../mk/bsd.pkg.mk"
