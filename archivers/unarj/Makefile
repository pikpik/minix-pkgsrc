# $NetBSD: Makefile,v 1.6 1998/12/26 15:46:10 garbled Exp $

DISTNAME=       unarj-2.43
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unarj ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
