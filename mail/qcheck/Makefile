# $NetBSD: Makefile,v 1.2 2001/03/12 21:39:49 zuntum Exp $
#

DISTNAME=	qcheck
PKGNAME=	qcheck-1.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.meanmachine.ch/pub/unix/qmail/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Text-only biff with Maildir support

NO_CONFIGURE=	YES

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/qcheck.c -o ${WRKSRC}/qcheck

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcheck ${PREFIX}/bin/qcheck

.include "../../mk/bsd.pkg.mk"
