# $NetBSD: Makefile,v 1.4 2001/02/25 04:18:04 hubertf Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	packages@netbsd.org
COMMENT=	Automatically download files via the FTP protocol

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
