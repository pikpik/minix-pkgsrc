# $NetBSD: Makefile,v 1.7 2002/12/09 00:05:27 cjep Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-20021129
CATEGORIES=	lang
MASTER_SITES=   http://cm.bell-labs.com/who/bwk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

DIST_SUBDIR=	${PKGNAME}

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
MAKEFLAGS+=	CC=${CC} YACC=${YACC} CFLAGS=${CFLAGS:Q}
ALL_TARGET=	a.out

post-build:
	${SED} -e 's|awk|nawk|g' -e 's/Awk/Nawk/g' \
		${WRKSRC}/awk.1 > ${WRKSRC}/nawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/nawk.1 ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
