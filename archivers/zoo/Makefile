# $NetBSD: Makefile,v 1.4 1998/02/09 00:33:12 hubertf Exp $
# FreeBSD Id: Makefile,v 1.8 1997/08/10 22:31:36 fenner Exp 
#

DISTNAME=       zoo-2.10pl1
PKGNAME=	zoo-2.10.1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes
ALL_TARGET=     bsdansi
MAKEFILE=       makefile
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"
MAN1=		fiz.1 zoo.1

.include "../../mk/bsd.pkg.mk"
