# $NetBSD: Makefile,v 1.4 2003/07/21 16:56:54 martti Exp $
#

DISTNAME=		qmailanalog-0.70
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity

USE_BUILDLINK3=		yes

ALL_TARGET=		it
INSTALL_TARGET=		setup check

RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/qmailanalog > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
