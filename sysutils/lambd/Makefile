# $NetBSD: Makefile,v 1.2 2001/07/13 23:12:18 itojun Exp $

DISTNAME=	lambd-20010718
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	itojun@netbsd.org
COMMENT=	shutdown switch monitoring daemon for Wildlab LAMB

EXTRACT_ONLY=	# none
NO_CHECKSUM=	yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/*.[ch8] ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
