# $NetBSD: Makefile,v 1.7 2000/08/16 00:41:13 wiz Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20001121
CATEGORIES=		x11
MASTER_SITES=		http://www.dkfz-heidelberg.de/spec/linux/modeline/
EXTRACT_SUFX=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.dkfz-heidelberg.de/spec/linux/modeline/

WRKSRC=			${WRKDIR}/modeline

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CPPFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
